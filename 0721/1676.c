#include <stdio.h>

int main() {
	int five = 0, five_pow = 0, five_pow2 = 0;
	int num;
	
	scanf("%d", &num);
	
	for (int i = 1; i <= num; i++) {
		if (!(i % 125))
			five_pow2 += 3;
		else if (!(i % 25))
			five_pow += 2;
		else if (!(i % 5))
			five++;
	}
	printf("%d", five + five_pow + five_pow2);
	
	return 0;
}
