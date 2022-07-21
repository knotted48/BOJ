#include <stdio.h>
#include <stdlib.h>

int Abs(int n) {
	return n * ((n > 0) - (n < 0));
}

int GCD(int n1, int n2) {
	int tmp;
	
	while (n1 % n2) {
		tmp = n1;
		n1 = n2;
		n2 = tmp % n1;
	}
	
	return n2;
}

int main() {
	int n, num1, num2, gcd;
	int *divisor, sqroot = 0, cnt = 1;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num1);
		
		if (i) {
			if (i == 1)
				gcd = Abs(num2 - num1);
			else {
				gcd = GCD(gcd, Abs(num1 - num2));
			}
		}
		
		num2 = num1;
	}
	
	for (int i = 2; i * i <= gcd; i++) {
		if (!(gcd % i))
			cnt++;
		if (i * i == gcd)
			sqroot = 1;
	}
	
	cnt += cnt + sqroot;
	divisor = malloc(sizeof(int) * cnt);
	divisor[0] = 1;
	
	cnt = 0;
	for (int i = 2; i * i <= gcd; i++) {
		if (!(gcd % i)) {
			divisor[++cnt] = i;
			printf("%d\n", i);
		}
	}
	cnt -= sqroot;
	for (int i = cnt; i >= 0; i--)
		printf("%d\n", gcd / divisor[i]);
	
	return 0;
}
