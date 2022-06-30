#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[21];
	int num;
} pocketmon;

void Swap(pocketmon* a, pocketmon* b) {
	pocketmon tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(pocketmon arr[], int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n && strcmp(arr[root].name, arr[left].name) < 0)
		root = left;
	
	if (right < n && strcmp(arr[root].name, arr[right].name) < 0)
		root = right;
	
	if (root != i) {
		Swap(&arr[i], &arr[root]);
		Heapify(arr, n, root);
	}
}

void HeapSort(pocketmon arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&arr[i], &arr[0]);
		Heapify(arr, i, 0);
	}
}

int BinarySearch(pocketmon* arr, int end, char* name) {
	int start = 0, mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (!strcmp(arr[mid].name, name))
			return arr[mid].num;
		else if (strcmp(arr[mid].name, name) > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
}

int main(void) {
	int n, m, ans;
	pocketmon *set;
	char **book, quest[21];
	
	scanf("%d%d", &n, &m);
	
	book = (char**)malloc(sizeof(char*) * n);
	set = (pocketmon*)malloc(sizeof(pocketmon) * n);
	
	for (int i = 0; i < n; i++) {
		book[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", book[i]);
		strcpy(set[i].name, book[i]);
		set[i].num = i + 1;
	}
	
	HeapSort(set, n);
	
	for (int i = 0; i < m; i++) {
		scanf("%s", quest);
		if (quest[0] >= '0' && quest[0] <= '9') {
			ans = atoi(quest);
			if (ans <= n)
				printf("%s\n", book[ans - 1]);
			continue;
		}
		ans = BinarySearch(set, n - 1, quest);
		if (ans)
			printf("%d\n", ans);
	}
	
	return 0;
}
