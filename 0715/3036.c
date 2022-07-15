#include <stdio.h>

int GCD(int n1, int n2) {
	int tmp;
	
	while (n1 % n2) {
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	
	return n2;
}

int main(void) {
	int n, ring, others, gcd_v;
	
	scanf("%d", &n);
	
	scanf("%d", &ring);
	for (int i = 1; i < n; i++) {
		scanf("%d", &others);
		gcd_v = GCD(ring, others);
		printf("%d/%d\n", ring / gcd_v, others / gcd_v);
	}
	
	return 0;
}
