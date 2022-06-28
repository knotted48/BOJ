#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(int* arr, int n, int i) {
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

void HeapSort(int* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(int* arr, int end, int num) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
        
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	
	return 0;
}

int main(void) {
	int n, m;
	int *sg, *num;
	
	scanf("%d", &n);
	
	sg = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &sg[i]);
	
	scanf("%d", &m);
	
	num = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &num[i]);
	
	HeapSort(sg, n);
	
	for (int i = 0; i < m; i++)
		printf("%d ", BinarySearch(sg, n - 1, num[i]));
    
    free(sg);
    free(num);
    
	return 0;
}
