#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
	char str[50];
	int len;
} word;

void Swap(word *a, word *b) {
	word tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(word arr[], int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n && arr[root].len < arr[left].len)
		root = left;
	else if (left < n && arr[root].len == arr[left].len
		&& strcmp(arr[root].str, arr[left].str) < 0)
		root = left;
	
	if (right < n && arr[root].len < arr[right].len)
		root = right;
	else if (right < n && arr[root].len == arr[right].len
		&& strcmp(arr[root].str, arr[right].str) < 0)
		root = right;
	
	if (root != i) {
		Swap(&arr[i], &arr[root]);
		Heapify(arr, n, root);
	}
}

void HeapSort(word arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

int main(void) {
	int n;
	word *data, tmp;
	
	scanf("%d", &n);
	
	data = (word*)malloc(sizeof(word) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", data[i].str);
		data[i].len = strlen(data[i].str);
	}
	
	HeapSort(data, n);
	
	for (int i = 0; i < n; i++) {
		if (i && !strcmp(tmp.str, data[i].str))
			continue;
		printf("%s\n", data[i].str);
		tmp = data[i];
	}
	
	return 0;
}
