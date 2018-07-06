# LinuxDeviceDriver
Repository to learn Linux Device Driver Development

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