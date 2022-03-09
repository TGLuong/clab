#include <linux/module.h>

static int main_init(void) {
	printk("bat dau module\n");
	int matrix[3][6] = {
		{0, 1, 2, 3, 4, 5},
		{6, 7, 8, 9,10,11},
		{12,13,14,15,16,17}
	}, i, j, min, max;

	min = matrix[0][0];
	max = matrix[0][0];

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
			if (min > matrix[i][j]) min = matrix[i][j];
			if (max < matrix[i][j]) max = matrix[i][j];
		}
	}
	printk("max = %d, min = %d\n", max, min);
	return 0;
}

static void main_exit(void) {
	printk("exit module\n");
}

module_init(main_init);
module_exit(main_exit);
