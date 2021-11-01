
/*All the kernel headers are there in LINUX_SRC/include/lin=ux
#include <linux/module.h>

/* This is modules for initialization */
static int __init firewall_module_init(void)
{
	pr_info("Hello ..  Welcome to Linux Firewall module.\n");
	return 0;
}


static void __exit firewall_module_exit(void)
{
	pr_info("Exiting linux firewall module\n");
}




