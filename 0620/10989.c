#include <stdio.h>

int main() {
	int n, num;
	int count[10000] = {0, };
	int max = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		count[num - 1]++;
		if (max < num)
			max = num;
	}
	
	for (int i = 0; i < max; i++)
		if (count[i] != 0)
			for (int j = 0; j < count[i]; j++)
				printf("%d\n", i + 1);

	return 0;
}
