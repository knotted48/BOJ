#include <stdio.h>

int check(int *board, int dep) {
	for (int i = 0; i < dep; i++)
		if (board[i] == board[dep] || dep - i == board[dep] - board[i] || dep + board[dep] == i + board[i])
			return 0;
	return 1;
}

void position(int *board, int N, int dep, int *cnt) {
	if (dep == N) {
		*cnt += 1;
		return ;
	}
	for (int i = 0; i < N; i++) {
		board[dep] = i;
		if (check(board, dep))
			position(board, N, dep + 1, cnt);
	}
}

int main() {
	int N, board[15], cnt = 0;
	
	for (int i = 0; i < 15; i++)
		board[i] = -1;
	scanf("%d", &N);
	position(board, N, 0, &cnt);
	printf("%d", cnt);
	
	return 0;
}
