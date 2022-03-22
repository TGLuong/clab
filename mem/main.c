#include <asm/io.h>
#include <asm/page.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/types.h>

static int md_start(void) {
    void * mem = kmalloc(1000, GFP_USER);
    uint64_t addr = virt_to_phys(mem);
    printk("physical memory: %llx\n", addr);
    printk("virtual memory: %p\n", mem);
    printk("page frame number: %d\n", addr > PAGE_SHIFT);
    kfree(mem);
    return 0;
}

static void md_exit(void) {

}


module_init(md_start);
module_exit(md_exit);
