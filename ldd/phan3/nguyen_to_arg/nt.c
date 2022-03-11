#include <linux/module.h>
#include <linux/moduleparam.h>

int is_prime(int value) {
    int i;
    if (value <= 1) return 0;
    if (value == 2) return 1;
    for (i = 2; i <= value / 2 + 1; i++) {
        if (value % i == 0) return 0;
    }
    return 1;
}

int a[20];
int size_a;
module_param_array(a, int, &size_a, 0);



static int md_init(void) {
	int i;
	for (i = 0; i < size_a; i++) {
		if (is_prime(a[i]) == 1) printk("so nt: %d\n", a[i]);
	}
	return 0;
}

static void md_exit(void) {
	printk("exit module\n");
}


module_init(md_init);
module_exit(md_exit);
