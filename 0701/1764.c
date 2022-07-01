#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char* a, char* b) {
	char tmp[21];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

void Heapify(char** arr, int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n && strcmp(arr[root], arr[left]) < 0)
		root = left;
	
	if (right < n && strcmp(arr[root], arr[right]) < 0)
		root = right;
	
	if (root != i) {
		Swap(arr[root], arr[i]);
		Heapify(arr, n, root);
	}
}

void Heapsort(char** arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(arr[i], arr[0]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(char** arr, int end, char* str) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (!strcmp(arr[mid], str))
			return mid;
		else if (strcmp(arr[mid], str) > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
	
	return -1;
}

int main(void) {
	int n, m, cnt = 0;
	char **heard, **saw;
	
	scanf("%d%d", &n, &m);
	
	heard = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		heard[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", heard[i]);
	}
	
	Heapsort(heard, n);
	
	saw = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < m; i++) {
		saw[i - cnt] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", saw[i - cnt]);
		if (BinarySearch(heard, n - 1, saw[i - cnt]) == -1) {
			saw[i - cnt] = NULL;
			cnt++;
		}
	}
	
	Heapsort(saw, m - cnt);
	
	printf("%d\n", m - cnt);
	
	for (int i = 0; i < m - cnt; i++)
		printf("%s\n", saw[i]);
	
	return 0;
}
