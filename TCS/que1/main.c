#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


struct people {
	int height;
	int pre;
};

int sorter(const void *p1, const void *p2) {
	return ((struct people *)p1)->height - ((struct people *)p2)->height;
}

int main() {
	int t;
	freopen("./data.txt", "r", stdin);
	scanf("%d", &t);

	for (int k = 0; k < t; k++) {
		int res[1005], n;
		struct people que[1005];
		memset(res, -1, sizeof(res));
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			scanf("%d", &que[j].height);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &que[j].pre);
		}

		qsort(que, n, sizeof(struct people), sorter);
		for (int i = 0; i < n; i++) {
			if (res[i] == -1) {
				if (que[i].pre == 0) {
					res[i] = que[i].height;
					break;
				} else {
					que[current].pre--;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}
