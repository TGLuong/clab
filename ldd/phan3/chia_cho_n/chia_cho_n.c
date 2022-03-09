#include <linux/module.h>

static int chia_n_init(void) {
	printk("bat dau module chia het\n");
	int matrix[3][6] = {
		{ 1, 2, 3, 4, 5, 6},
		{ 7, 8, 9,10,11,12},
		{13,14,15,16,17,18},
	}, i, j, n = 4, count = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
			if (matrix[i][j] % n == 0) count++;
		}
	}
	printk("so chia het cho n = %d\n", count);
	return 0;
}

static void chia_n_exit(void) {
	printk("exit module\n");
}

module_init(chia_n_init);
module_exit(chia_n_exit);
