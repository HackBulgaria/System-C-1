#!/bin/sh
module="skeletor"
devname="usb_device"
device="skeletor"
mode=664
group="wheel"

load()
{
	shift
    modprobe -r usbhid
	modprobe -r usbcore
	insmod ./${module}.ko $* || exit 1


    echo " awk "\$2==\"${devname}\" {print \$1}" /proc/devices"
	major=$(awk "\$2==\"${devname}\" {print \$1}" /proc/devices)
        echo "major: $(major)"
	for i in 0 ; do
		mknod -m ${mode} "/dev/${device}${i}" c ${major} ${i}
		echo mknod -m ${mode} "/dev/${device}${i}" c ${major} ${i}

	done

 ${group} /dev/${device}0
}

unload()
{
	rmmod ${module} || exit 1
	rm -f /dev/${device}0
}

case $1 in
	load)
	load $*
	;;
	unload)
	unload
	;;
	reload)
	unload
	load $*
	;;
	*)
	echo "usage: $0 <load|unload|reload>"
	;;
esac
