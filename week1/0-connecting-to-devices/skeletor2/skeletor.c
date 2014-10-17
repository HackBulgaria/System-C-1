/*
 *  Copyright (c) 1999-2001 Vojtech Pavlik
 *
 *  USB HIDBP Mouse support
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Should you need to contact me, the author, you can do so either by
 * e-mail - mail your message to <vojtech@ucw.cz>, or by paper mail:
 * Vojtech Pavlik, Simunkova 1594, Prague 8, 182 00 Czech Republic
 */

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb/input.h>
#include <linux/hid.h>


/*
 * Version Information
 */
#define DRIVER_VERSION "v1.6"
#define DRIVER_AUTHOR "Vojtech Pavlik <vojtech@ucw.cz>"
#define DRIVER_DESC "USB HID Boot Protocol skeletor driver"
#define DRIVER_LICENSE "GPL"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE(DRIVER_LICENSE);

struct usb_skeletor {
	char name[128];
	char phys[64];
	struct usb_device *usbdev;
	struct input_dev *dev;
	struct urb *irq;

	signed char *data;
	dma_addr_t data_dma;
};

static void usb_skeletor_irq(struct urb *urb)
{
	struct usb_skeletor *skeletor = urb->context;
	signed char *data = skeletor->data;
	struct input_dev *dev = skeletor->dev;
	int status;
	printk(KERN_WARNING "%s %s\n",__FILE__, __FUNCTION__);
	switch (urb->status) {
	case 0:			/* success */
		break;
	case -ECONNRESET:	/* unlink */
	case -ENOENT:
	case -ESHUTDOWN:
		return;
	/* -EPIPE:  should clear the halt */
	default:		/* error */
		goto resubmit;
	}
	printk(KERN_WARNING "inputing %s %s\n",__FILE__, __FUNCTION__);
	
	input_report_key(dev, BTN_LEFT,   data[0] & 0x01);
	input_report_key(dev, BTN_RIGHT,  data[0] & 0x02);
	input_report_key(dev, BTN_MIDDLE, data[0] & 0x04);
	input_report_key(dev, BTN_SIDE,   data[0] & 0x08);
	input_report_key(dev, BTN_EXTRA,  data[0] & 0x10);

	input_report_rel(dev, REL_X,     data[1]);
	input_report_rel(dev, REL_Y,     data[2]);
	input_report_rel(dev, REL_WHEEL, data[3]);

	input_sync(dev);
resubmit:
	printk(KERN_WARNING "resubmiting %s %s\n",__FILE__, __FUNCTION__);

	status = usb_submit_urb (urb, GFP_ATOMIC);
	if (status)
		dev_err(&skeletor->usbdev->dev,
			"can't resubmit intr, %s-%s/input0, status %d\n",
			skeletor->usbdev->bus->bus_name,
			skeletor->usbdev->devpath, status);
}

static int usb_skeletor_open(struct input_dev *dev)
{
	struct usb_skeletor *skeletor = input_get_drvdata(dev);
	printk(KERN_WARNING "%s %s\n",__FILE__, __FUNCTION__);

	skeletor->irq->dev = skeletor->usbdev;
	if (usb_submit_urb(skeletor->irq, GFP_KERNEL))
		return -EIO;

	return 0;
}

static void usb_skeletor_close(struct input_dev *dev)
{
	struct usb_skeletor *skeletor = input_get_drvdata(dev);
	printk(KERN_WARNING "%s %s\n",__FILE__, __FUNCTION__);

	usb_kill_urb(skeletor->irq);
}

static int usb_skeletor_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	struct usb_device *dev = interface_to_usbdev(intf);
	struct usb_host_interface *interface;
	struct usb_endpoint_descriptor *endpoint;
	struct usb_skeletor *skeletor;
	struct input_dev *input_dev;
	int pipe, maxp;
	int error = -ENOMEM;
	printk(KERN_WARNING "%s %s\n",__FILE__, __FUNCTION__);

	interface = intf->cur_altsetting;

	if (interface->desc.bNumEndpoints != 1)
		return -ENODEV;

	endpoint = &interface->endpoint[0].desc;
	if (!usb_endpoint_is_int_in(endpoint))
		return -ENODEV;

	pipe = usb_rcvintpipe(dev, endpoint->bEndpointAddress);
	maxp = usb_maxpacket(dev, pipe, usb_pipeout(pipe));

	skeletor = kzalloc(sizeof(struct usb_skeletor), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!skeletor || !input_dev)
		goto fail1;

	skeletor->data = usb_alloc_coherent(dev, 8, GFP_ATOMIC, &skeletor->data_dma);
	if (!skeletor->data)
		goto fail1;

	skeletor->irq = usb_alloc_urb(0, GFP_KERNEL);
	if (!skeletor->irq)
		goto fail2;

	skeletor->usbdev = dev;
	skeletor->dev = input_dev;

	if (dev->manufacturer)
		strlcpy(skeletor->name, dev->manufacturer, sizeof(skeletor->name));

	if (dev->product) {
		if (dev->manufacturer)
			strlcat(skeletor->name, " ", sizeof(skeletor->name));
		strlcat(skeletor->name, dev->product, sizeof(skeletor->name));
	}

	if (!strlen(skeletor->name))
		snprintf(skeletor->name, sizeof(skeletor->name),
			 "USB HIDBP Mouse %04x:%04x",
			 le16_to_cpu(dev->descriptor.idVendor),
			 le16_to_cpu(dev->descriptor.idProduct));

	usb_make_path(dev, skeletor->phys, sizeof(skeletor->phys));
	strlcat(skeletor->phys, "/skeletor0", sizeof(skeletor->phys));
	printk("skeletor device created, it writes in %s\n", skeletor->phys);

	input_dev->name = skeletor->name;
	input_dev->phys = skeletor->phys;
	usb_to_input_id(dev, &input_dev->id);
	input_dev->dev.parent = &intf->dev;

	input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
	input_dev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_LEFT) |
		BIT_MASK(BTN_RIGHT) | BIT_MASK(BTN_MIDDLE);
	input_dev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y);
	input_dev->keybit[BIT_WORD(BTN_MOUSE)] |= BIT_MASK(BTN_SIDE) |
		BIT_MASK(BTN_EXTRA);
	input_dev->relbit[0] |= BIT_MASK(REL_WHEEL);

	input_set_drvdata(input_dev, skeletor);

	input_dev->open = usb_skeletor_open;
	input_dev->close = usb_skeletor_close;

	usb_fill_int_urb(skeletor->irq, dev, pipe, skeletor->data,
			 (maxp > 8 ? 8 : maxp),
			 usb_skeletor_irq, skeletor, endpoint->bInterval);
	skeletor->irq->transfer_dma = skeletor->data_dma;
	skeletor->irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;

	error = input_register_device(skeletor->dev);
	if (error)
		goto fail3;

	usb_set_intfdata(intf, skeletor);
	return 0;

fail3:	
	usb_free_urb(skeletor->irq);
fail2:	
	usb_free_coherent(dev, 8, skeletor->data, skeletor->data_dma);
fail1:	
	input_free_device(input_dev);
	kfree(skeletor);
	return error;
}

static void usb_skeletor_disconnect(struct usb_interface *intf)
{
	struct usb_skeletor *skeletor = usb_get_intfdata (intf);
	printk(KERN_WARNING "%s %s",__FILE__, __FUNCTION__);

	usb_set_intfdata(intf, NULL);
	if (skeletor) {
		usb_kill_urb(skeletor->irq);
		input_unregister_device(skeletor->dev);
		usb_free_urb(skeletor->irq);
		usb_free_coherent(interface_to_usbdev(intf), 8, skeletor->data, skeletor->data_dma);
		kfree(skeletor);
	}
}

static struct usb_device_id usb_skeletor_id_table [] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_MOUSE) },
	{ }	/* Terminating entry */
};

MODULE_DEVICE_TABLE (usb, usb_skeletor_id_table);

static struct usb_driver usb_skeletor_driver = {
	.name		= "usbskeletor",
	.probe		= usb_skeletor_probe,
	.disconnect	= usb_skeletor_disconnect,
	.id_table	= usb_skeletor_id_table,
};

module_usb_driver(usb_skeletor_driver);
