#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

