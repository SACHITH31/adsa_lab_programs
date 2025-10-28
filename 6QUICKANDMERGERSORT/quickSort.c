#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (arr[left] <= pivot && left <= high - 1) {
            left++;
        }

        while (arr[right] > pivot && right >= low + 1) {
            right --;
        }

        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[low], &arr[right]);
    return right;
}

void quickSort (int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi -1);
        quickSort(arr, pi + 1, high);
    }
}


int main () {
    int n; 
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}