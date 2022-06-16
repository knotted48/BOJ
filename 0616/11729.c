#include <stdio.h>

int pow2(int power) {
	if (power == 0)
		return 1;
	if (power == 1)
		return 2;
	else
		return 2 * pow2(power - 1);
}

void hanoi(int n, int p1, int p2, int p3) {
	if (n == 1)
		printf("%d %d\n", p1, p3);
	else {
		hanoi(n - 1, p1, p3, p2);
		printf("%d %d\n", p1, p3);
		hanoi(n - 1, p2, p1, p3);
	}
}

int main(void) {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", pow2(n) - 1);
	hanoi(n, 1, 2, 3);
	return 0;
}
