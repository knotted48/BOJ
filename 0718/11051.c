#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int **dp, n, k;
	
	scanf("%d%d", &n, &k);
	++n;
	++k;
	dp = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		dp[i] = malloc(sizeof(int) * k);
		for (int j = 0; j < k && j <= i; j++) {
			if (i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
				// C(n, r) = C(n-1, r) + C(n-1, r-1)
		}
	}
	
	printf("%d", dp[n - 1][k - 1]);
	
	return 0;
}
