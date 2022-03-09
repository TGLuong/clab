KDIR = /lib/modules/`uname -r`/build

all:
	make -C $(KDIR) M=`pwd`
clear:
	make -C $(KDIR) M=`pwd` clear

reinstall: remove install

install:
	sudo insmod lon_hon_n.ko
remove:
	sudo rmmod lon_hon_n 

