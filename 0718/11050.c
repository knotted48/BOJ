#include <stdio.h>

int factorial(int start, int end) {
	if (start < 2 || start == end)
		return 1;
	else if (start == end + 1)
		return start;
	return start * factorial(start - 1, end);
}

int main(void) {
	int n, k;
	
	scanf("%d%d", &n, &k);
	printf("%d", factorial(n, k) / factorial(n - k, 1));
	
	return 0;
}
