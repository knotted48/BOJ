#include <stdio.h>

int main() {
    int n, fib[40];
    
    scanf("%d", &n);
    
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    printf("%d %d\n", fib[n - 1], n - 2);
}
