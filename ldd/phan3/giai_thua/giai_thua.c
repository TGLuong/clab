#include <linux/module.h>


static int is_prime(int value) {
	int i;
	if (value <= 1) return 0;
	if (value == 2) return 1;
	for (i = 2; i <= value / 2 + 1; i++) {
		if (value % i == 0) return 0;
	}
	return 1;
}

static int nt_init(void) {
	printk("bat dau module nguyen to\n");
	int matrix[3][6] = {
		{ 1, 2, 3, 4, 5, 6},
		{ 7, 8, 9,10,11,12},
		{13,14,15,16,17,18}
	}, i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
			if (is_prime(matrix[i][j]) == 1) printk("so nt: %d\n", matrix[i][j]);
		}
	}
	return 0;
}

static void nt_exit(void) {
	
}

module_init(nt_init);
module_exit(nt_exit);

