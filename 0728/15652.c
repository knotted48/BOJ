#include <stdio.h>

int check(int *arr, int dep) {
	for (int i = 0; i < dep; i++) {
		if (arr[i] > arr[dep])
			return 0;
	}
	return 1;
}
void sequence(int *arr, int n, int m, int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[dep] = i;
		if (check(arr, dep))
			sequence(arr, n, m, dep + 1);
	}
}

int main() {
	int n, m, arr[8];
	
	for (int i = 0; i < 8; i++)
		arr[i] = -1;
	scanf("%d%d", &n, &m);
	sequence(arr, n, m, 0);

	return 0;
}
