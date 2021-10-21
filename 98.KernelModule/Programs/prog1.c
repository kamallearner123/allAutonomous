#include <linux/init.h>
#include <linux/module.h>

int __init hello_init()
{
    printk(KERN_ALERT"mymodule: Hello world\n");
    return();
}


int __exit hello_exit()
{
    printk(KERN_MODULE"My module: Good bye\n");
}


module_init(hello_init);
module_exit(hello_exit);



