#include <stdio.h>

int star(int n, int row, int col) {
	if ((row / n) % 3 == 1 && (col / n) % 3 == 1)
		printf(" ");
	else {
		if (n / 3 == 0)
			printf("*");
		else
			star(n / 3, row, col);
	}
}

int main() {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			star(n, i, j);
		printf("\n");
	}
}
