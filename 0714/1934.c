#include <stdio.h>

int main(void) {
	int t, n1, n2, mul, tmp;
	
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &n1, &n2);
		
		mul = n1 * n2;
		while (n1 % n2) {
			tmp = n1;
			n1 = n2;
			n2 = tmp % n2;
		}
		
		printf("%d\n", mul / n2);
	}
	
	return 0;
}
