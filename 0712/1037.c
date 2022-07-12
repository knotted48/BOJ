#include <stdio.h>

int main(void) {
	int n, number, max, min;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		if (!i) {
			max = number;
			min = number;
		}
		else if (number > max)
			max = number;
		else if (number < min)
			min = number;
	}
	
	printf("%d", max * min);
	
	return 0;
}
