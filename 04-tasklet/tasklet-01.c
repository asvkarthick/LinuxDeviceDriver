#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

/* for tasklets API */
char tasklet_data[] = "We use a string; but it could be pointer to a structure";

/* Tasklet handler, that just print the data */
void tasklet_work(unsigned long data)
{
	printk("%s\n", (char *)data);
}

DECLARE_TASKLET(my_tasklet, tasklet_work, (unsigned long) tasklet_data);

static int __init my_init(void)
{
	/*
	 * Schedule the handler.
	 * Tasklet arealso scheduled from interrupt handler
	 */
	tasklet_schedule(&my_tasklet);

	return 0;
}

void my_exit(void)
{
	tasklet_kill(&my_tasklet);
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
