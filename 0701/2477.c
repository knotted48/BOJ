#include <stdio.h>

int main(void) {
	int k, dir, edge[6], width = 0, height = 0;
	
	scanf("%d", &k);
	
	for (int i = 0; i < 6; i++) {
		scanf("%d%d", &dir, &edge[i]);
		if (dir / 3 == 1 && edge[i] > height)
			height = edge[i];
		else if (dir / 3 == 0 && edge[i] > width)
			width = edge[i];
	}
	
	for (int i = 0; i < 6; i++) {
		if (edge[i] + edge[(i + 1) % 6] + edge[(i + 2) % 6] + edge[(i + 3) % 6] == height + width)
			printf("%d", (height * width - edge[(i + 1) % 6] * edge[(i + 2) % 6]) * k);
	}
	
	return 0;
}
