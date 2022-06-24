#include <stdio.h>
#include <stdlib.h>

typedef struct personal_data {
	int num;
	int age;
	char name[101];
} member;

void Swap(member *a, member *b) {
	member tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(member mem[], int n, int i) {
	int root = i;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	
	if (left < n) {
		if (mem[root].age < mem[left].age)
			root = left;
		else if (mem[root].age == mem[left].age && mem[root].num < mem[left].num)
			root = left;
	}
	
	if (right < n) {
		if (mem[root].age < mem[right].age)
			root = right;
		else if (mem[root].age == mem[right].age && mem[root].num < mem[right].num)
			root = right;
	}
	
	if (root != i) {
		Swap(&mem[root], &mem[i]);
		Heapify(mem, n, root);
	}
}

void SortMem(member* mem, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(mem, n, i);
	for (int i = n - 1; i >= 0; i--) {
		Swap(&mem[0], &mem[i]);
		Heapify(mem, i, 0);
	}
}

int main(void) {
	member *mem;
	int n;
	
	scanf("%d", &n);
	mem = (member*)malloc(sizeof(member) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &mem[i].age, mem[i].name);
		mem[i].num = i;
	}
	
	SortMem(mem, n);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", mem[i].age, mem[i].name);
	
	return 0;
}
