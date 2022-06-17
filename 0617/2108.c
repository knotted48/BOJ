#include <stdio.h>
#include <stdlib.h>

int CountingSort(int* arr, int n) {
	int count[8001] = {0};
	int *mode;
	int max = 0, idx = 0, mode_cnt = 0, mode_idx = 0;
	
	mode = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		count[arr[i] + 4000]++;
		if (max < arr[i] + 4000)
			max = arr[i] + 4000;
	}
	
	mode[0] = count[0];
	
	for (int i = 0; i <= max; i++) {
		if (count[i] != 0) {
			if (count[mode_idx] == count[i])
				mode_cnt++;
			else if (count[mode_idx] < count[i]) {
				mode[0] = i - 4000;
				mode_idx = i;
				mode_cnt = 1;
			}
			for (int j = 0; j < count[i]; j++) {
				arr[idx++] = i - 4000;
			}
		}
	}
	
	idx = 0;
	for (int i = mode_idx + 1; i <= max; i++) {
		if (count[mode_idx] == count[i]) {
			mode[++idx] = i - 4000;
		}
	}
	
	if (mode_cnt == 1)
		return mode[0];
	return mode[1];
}

int Avg(int sum, int n) {
	if (sum == 0)
		return 0;
	else if (sum > 0)
		return (int)(sum * 1.0 / n + 0.5);
	else
		return (int)(sum * 1.0 / n - 0.5);
}

int main(void) {
	int n, sum = 0, mode;
	int* num;
	
	scanf("%d", &n);
	num = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
	}
	
	mode = CountingSort(num, n);
	printf("%d\n", Avg(sum, n));
	printf("%d\n", num[n / 2]);
	printf("%d\n", mode);
	printf("%d\n", num[n - 1] - num[0]);
}
