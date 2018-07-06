Building the kernel module:
---------------------------

make -C < /path-to-kernel> M=$(pwd) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- modules

Cleaning the kernel module:
---------------------------

make -C < /path-to-kernel> M=$(pwd) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- modules

Running the kernel module on Beaglebone:
----------------------------------------
Copy the kernel module to Beaglebone filesystem from your development environment, for example

# scp module_param-01.ko root@192.168.7.2:/tmp

Running the kernel module without passing any parameters (Use dmesg to see the result)

#insmod module_param-01.ko
#dmesg

[   82.715870] Hello, world
[   82.715919] short var: 0
[   82.715940] integer var: 0
[   82.715961] string: string

#rmmod module_param-01.ko
#dmesg
[   92.184333] Goodbye, world

#insmod module_param-01.ko short_var=100 int_var=200 string="Linux Kernel Module"
#dmesg

[  476.850632] Hello, world
[  476.850678] short var: 100
[  476.850699] integer var: 200
[  476.850721] string: LinuxKernelModule

#rmmod module_param-01.ko
#dmesg
[  521.861401] Goodbye, world
