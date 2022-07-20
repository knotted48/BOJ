#include <stdio.h>
#include <string.h>

int main() {
	int t, n, type_cnt, cnt_each_type[30], day;
	char closet[30][21], type_name[21];
	
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		
		for (int j = 0; j < n; j++) {
			cnt_each_type[j] = 1;
			memset(closet[j], 0, 21);
		}
		type_cnt = 0;
		
		for (int j = 0; j < n; j++) {
			scanf("%s %s", type_name, type_name);
			for (int k = type_cnt; k >= 0; k--) {
				if (!strcmp(type_name, closet[k])) {
					cnt_each_type[k]++;
					break;
				}
				if (k == 0) {
					cnt_each_type[type_cnt]++;
					strcpy(closet[type_cnt++], type_name);
				}
			}
		}

		day = 1;
		for (int j = 0; j < type_cnt; j++)
			day *= cnt_each_type[j];
			
		printf("%d\n", (day - 1) * (type_cnt != 0));
	}
}
