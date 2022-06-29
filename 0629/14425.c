#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *a[], char *b[]) {
	char tmp[501];
	strcpy(tmp, *a);
	strcpy(*a, *b);
	strcpy(*b, tmp);
}

void Heapify(char *arr[], int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n && strcmp(arr[root], arr[left]) < 0)
		root = left;
	
	if (right < n && strcmp(arr[root], arr[right]) < 0)
		root = right;
	
	if (root != i) {
		Swap(&arr[root], &arr[i]);
		Heapify(arr, n, root);
	}
}

void HeapSort(char *arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
		
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(char *arr[], int end, char str[]) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (!strcmp(arr[mid], str))
			return 1;
		else if (strcmp(arr[mid], str) > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
}

int main(void) {
	int n, m, cnt = 0;
	char **set, str[501];
	
	scanf("%d%d", &n, &m);
	set = (char**)malloc(sizeof(char*) * n);
	
	for (int i = 0; i < n; i++) {
		set[i] = (char*)malloc(sizeof(char) * 501);
		scanf("%s", set[i]);
	}
	
	HeapSort(set, n);
	
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		if (BinarySearch(set, n - 1, str))
			cnt++;
	}
	
	printf("%d", cnt);
}
