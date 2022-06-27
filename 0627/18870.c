#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(int* arr, int n, int i) {
	int root = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	
	if (left < n && arr[root] < arr[left])
		root = left;
	
	if (right < n && arr[root] < arr[right])
		root = right;
	
	if (root != i) {
		Swap(&arr[root], &arr[i]);
		Heapify(arr, n, root);
	}
}

void HeapSort(int* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(int *arr, int end, int num) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (arr[mid] == num)
			return mid;
		else if (arr[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
}

int main(void) {
	int n, *arr, *sorted, *ordered, cnt = 0;
	
	scanf("%d", &n);
	
	arr = (int*)malloc(sizeof(int) * n);
	sorted = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sorted[i] = arr[i];
	}
	
	HeapSort(sorted, n);
	
	ordered = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		if (i && sorted[i - 1] == sorted[i])
			continue;
		ordered[cnt] = sorted[i];
		cnt++;
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", BinarySearch(ordered, cnt - 1, arr[i]));
	}
	
	return 0;
}
