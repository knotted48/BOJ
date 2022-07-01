#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(int *arr, int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n && arr[root] < arr[left])
		root = left;
	
	if (right < n && arr[root] < arr[right])
		root = right;
	
	if (root != i) {
		Swap(&arr[root], &arr[i]);
		Heapify(arr, n, root);
	}
}

void HeapSort(int *arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[i], &arr[0]);
		Heapify(arr, i, 0);
	}
}

int UpperBound(int *arr, int num, int end) {
	int start = 0, mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		
		if (arr[mid] > num)
			end = mid;
		else
			start = mid + 1;
	}
	
	return end;
}

int LowerBound(int *arr, int num, int end) {
	int start = 0, mid;
	
	while (start < end) {
		mid = (start + end) / 2;
		
		if (arr[mid] >= num)
			end = mid;
		else
			start = mid + 1;
	}
	
	return end;
}

int main(void) {
	int n, m, *set, card;
	
	scanf("%d", &n);
	set = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &set[i]);
	
	HeapSort(set, n);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &card);
		printf("%d ", UpperBound(set, card, n) - LowerBound(set, card, n));
	}
	
	free(set);
	
	return 0;
}
