#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate {
    int x;
    int y;
} xy;

void Swap(xy *a, xy *b) {
    xy tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(xy arr[], int n, int i) {
    int root = i;
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    
    if (left < n && arr[root].x < arr[left].x)
        root = left;
    else if (left < n && arr[root].x == arr[left].x && arr[root].y < arr[left].y)
        root = left;
    
    if (right < n && arr[root].x < arr[right].x)
        root = right;
    else if (right < n && arr[root].x == arr[right].x && arr[root].y < arr[right].y)
        root = right;
    
    if (root != i) {
        Swap(&arr[i], &arr[root]);
        Heapify(arr, n, root);
    }
}

void HeapSort(xy arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    
    for (int i = n - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

int main(void) {
    int n;
    xy *pair;
    
    scanf("%d", &n);
    
    pair = (xy*)malloc(sizeof(xy) * n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &pair[i].x, &pair[i].y);
    
    HeapSort(pair, n);
    
    for (int i = 0; i < n; i++)
        printf("%d %d\n", pair[i].x, pair[i].y);
    
    return 0;
}
