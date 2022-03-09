#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int sorter(const void *p1, const void *p2) {
	int *val1 = (int*)p1, *val2 = (int*)p2;
	return *val1 - *val2;
}
int main() {
	int n, k, sum = 0;
	int *arr;
	scanf("%d%d", &n, &k);
	arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), sorter);
	for (int i = 0; i < n; i++) {
		if (arr[i] >= k) {
			int index = binarySearch(arr, 0, n - 1, arr[i] - k);
			if (index != -1) {
				sum++;
				for (int j = index + 1; j < n && arr[i] - k == arr[j]; j++) sum++;
				for (int j = index - 1; j >= 0 && arr[i] - k == arr[j]; j--) sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
