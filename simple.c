/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/jiffies.h>
#include <asm/param.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       unsigned long int j = jiffies;
       int j_freq = HZ;

       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
       printk(KERN_INFO "The value for jiffies is %lu\n", j);
       printk(KERN_INFO "The frquency is %d\n", j_freq);
 
      // unsigned long gcd(unsigned long a, unsigned b);
      	
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	unsigned long int a = 3300;
	unsigned int b = 24;
	unsigned long int j = jiffies;

	printk(KERN_INFO "Removing Module\n");
	printk(KERN_INFO "The GCD of %lu and %u is %lu\n", a, b, gcd(a, b));
	printk(KERN_INFO "The value for jiffies is %lu\n" , j);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

