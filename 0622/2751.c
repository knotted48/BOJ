#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(int arr[], int n, int i) {
    int root = i;
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    
    if (left < n && arr[root] < arr[left])
        root = left;
    
    if (right < n && arr[root] < arr[right])
        root = right;
    
    if (root != i) {
        Swap(&arr[i], &arr[root]);
        Heapify(arr, n, root);
    }
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    
    for (int i = n - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

int main(void) {
    int n, *arr;
    
    scanf("%d", &n);
    
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    HeapSort(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}
