#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
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
		swap(&arr[root], &arr[i]);
		Heapify(arr, n, root);
	}
}

void Heapsort(int* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[i], &arr[0]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(int* arr, int end, int num) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (arr[mid] == num)
			return mid;
		else if (arr[mid] > num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	
	return -1;
}

int main(void) {
	int a, b, *A, *B, cnt = 0;
	
	scanf("%d%d", &a, &b);
	
	A = (int*)malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++)
		scanf("%d", &A[i]);
	
	Heapsort(A, a);
	
	B = (int*)malloc(sizeof(int) * b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &B[i]);
		if (BinarySearch(A, a - 1, B[i]) == -1)
			cnt++;
	}
	
	Heapsort(B, b);
	
	for (int i = 0; i < a; i++)
		if (BinarySearch(B, b - 1, A[i]) == -1)
			cnt++;
	
	free(A);
	free(B);
	
	printf("%d", cnt);
	
	return 0;
}
