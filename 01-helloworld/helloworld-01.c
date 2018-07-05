#include <linux/module.h>

static int __init helloworld_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;
}

static void __exit helloworld_exit(void)
{
    printk(KERN_INFO "End of the world\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
