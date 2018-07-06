# LinuxDeviceDriver
Repository to learn Linux Device Driver Development

All these kernel modules have been tested exclusively on Beaglebone Black with Linux Kernel 3.8

Installing the cross compiler toolchain on Ubuntu

```
sudo apt-get install gcc-arm-linux-gnueabi
```

Building the Kernel module

```
make -C < /path-to-kernel> M=$(pwd) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- modules
```

Cleaning the Kernel module

```
make -C < /path-to-kernel> M=$(pwd) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- clean
```