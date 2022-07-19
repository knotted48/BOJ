#include <stdio.h>

int main(void) {
	int t, n, m, comb;
	
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		comb = 1;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			comb *= m - i;
			comb /= 1 + i;
		}
		printf("%d\n", comb);
	}
}
