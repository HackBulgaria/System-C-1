#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7f29f26b, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x3ff2d332, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x3bc45b71, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x8057eafe, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xf9c0b663, __VMLINUX_SYMBOL_STR(strlcat) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xecdfdd1d, __VMLINUX_SYMBOL_STR(input_free_device) },
	{ 0xca4105b5, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x204fe0db, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0xb03cd0c4, __VMLINUX_SYMBOL_STR(input_allocate_device) },
	{ 0x8829c16f, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x43fea726, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x4cb81a4, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x15543716, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x541fd908, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x7b547815, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0xc2f339c2, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0xd2d61e9f, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0xe2f8dcb, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usbcore";

MODULE_ALIAS("usb:v*p*d*dc*dsc*dp*ic03isc01ip02in*");
