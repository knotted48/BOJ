#include <stdio.h>

int main(void) {
	int w, h, x, y, p, px, py,cnt = 0;
	int left, right, r;
	
	scanf("%d%d%d%d%d", &w, &h, &x, &y, &p);
	r = h / 2;
	
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &px , &py);
		left = (px - x) * (px - x) + (py - (y + r)) * (py - (y + r));
		right = (px - (x + w)) * (px - (x + w)) + (py - (y + r)) * (py - (y + r));
		
		if (px >= x && px <= x + w && py >= y && py <= y + h)
			cnt++;
		else if (left <= r * r || right <= r * r)
			cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
