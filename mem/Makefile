KDIR := /lib/modules/`uname -r`/build

all:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean

reins:
	sudo rmmod main
	sudo insmod main.ko
