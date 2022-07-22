#include <stdio.h>

int cnt_num(int n, int num) {
	int	cnt = 0;
	
	while(n) {
		cnt += n / num;
		n /= num;
	}
	return cnt;
}

int main() {
	int n, m;
	int five, two;
	
	scanf("%d%d", &n, &m);
	
	five = cnt_num(n, 5) - cnt_num(m, 5) - cnt_num(n - m, 5);
	two = cnt_num(n, 2) - cnt_num(m, 2) - cnt_num(n - m, 2);

	printf("%d", (five && two) * (five * (five <= two) + two * (five > two)));
	return 0;
}
