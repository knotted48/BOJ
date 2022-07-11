#include <stdio.h>

int main(void) {
	int n1 = 1, n2 = 1;
	
	while (1) {
		scanf("%d%d", &n1, &n2);
		
        if (!n1 || !n2)
            break;
        if (!(n2 % n1))
    	    printf("factor\n");
        else if (!(n1 % n2))
    		printf("multiple\n");
    	else
    		printf("neither\n");
	}
    
	return 0;
}
