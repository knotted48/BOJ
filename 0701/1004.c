#include <stdio.h>

int main(void) {
	int t, x1, y1, x2, y2, d1, d2;
	int n, cx, cy, r;
	int cnt;
	
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		
		scanf("%d", &n);
		
		cnt = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d%d%d", &cx, &cy, &r);
			d1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
			d2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
			if ((d1 < r * r && d2 > r * r) || (d1 > r * r && d2 < r * r))
				cnt++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
