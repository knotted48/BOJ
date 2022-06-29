#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n, m, cnt = 0, r;
	long long int *hash, hash_c;
	int *len, len_c;
	char str[501];
	
	scanf("%d%d", &n, &m);
	
	hash = malloc(sizeof(long long int) * n);
	len = malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		hash[i] = 0;
		r = 1;
		scanf("%s", str);
		len[i] = strlen(str);
		for (int j = 0; j < len[i]; j++) {
			if (j)
				r *= 31;
			hash[i] += r * (str[j] - 0x61);
			hash[i] %= 1234567891;
		}
	}
	
	for (int i = 0; i < m; i++) {
		hash_c = 0;
		r = 1;
		scanf("%s", str);
		len_c = strlen(str);
		for (int j = 0; j < len_c; j++) {
			if (j)
				r *= 31;
			hash_c += r * (str[j] - 0x61);
			hash_c %= 1234567891;
		}
		
		for (int j = 0; j < n; j++)
			if (hash[j] == hash_c && len[j] == len_c)
				cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
