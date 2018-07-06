#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

static short int short_var = 0;
static int int_var = 0;
static char *string = "string";

module_param(short_var, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(short_var, "A short integer variable");
module_param(int_var, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(int_var, "An integer variable");
module_param(string, charp, 0000);
MODULE_PARM_DESC(string, "A character string");


static int __init hello_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	printk(KERN_INFO "short var: %hd\n", short_var);
	printk(KERN_INFO "integer var: %d\n", int_var);
	printk(KERN_INFO "string: %s\n", string);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, world\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Karthick Kumaran <asvkarthick@gmail.com>");
MODULE_LICENSE("GPL");
