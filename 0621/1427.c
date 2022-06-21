#include <stdio.h>

int main(void) {
	char num_str[10];
	int count[10] = {0, }, idx = -1;
	
	scanf("%s", num_str);
	
	while (num_str[++idx])
		count[num_str[idx] - '0']++;

	for (int i = 9; i >= 0; i--)
		if (count[i] != 0)
			for (int j = 0; j < count[i]; j++)
				printf("%d", i);
	
    return 0;
}
