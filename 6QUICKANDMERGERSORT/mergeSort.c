#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return ;
    }
    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}


void merge(int arr[], int low, int mid, int high) {
    int size = high - low + 1;
    int *temp = (int*)malloc(size*sizeof(int));

    int left = low;
    int right = mid + 1;
    int counter = 0;

    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp[counter++] = arr[left++];
        } else {
            temp[counter++] = arr[right++];
        }
    }
    
    while (left <= mid) {
        temp[counter++] = arr[left++];
    }
    while (right <= high) {
        temp[counter++] = arr[right++];
    }

    for (int i = 0; i < size; i++) {
        arr[i + low] = temp[i];
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

    mergeSort(arr, 0, n - 1);
    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    return 0;

}