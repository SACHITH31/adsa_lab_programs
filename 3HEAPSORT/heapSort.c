//heap sort

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify (int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, i);
    }
}

void heapSort (int arr[], int n) {
    int i;
    for (i = n/2-1; i >=0; i--) {
        heapify(arr, n, i);
    }
    for (i = n-1; i >=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray (int arr[], int n) {
    printf("Sorted Array is: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main () {
    int *arr, i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));

    if (arr == NULL) {
        printf("Memory is not allocated");
    } else {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    }

    heapSort(arr, n);
    printArray(arr, n);
}