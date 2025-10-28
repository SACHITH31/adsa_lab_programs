#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSafe (char mat[][10], int r, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (mat[i][c] == 'Q') {
            return false;
        }
    }

    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (mat[i][j] == 'Q') {
            return false;
        }
    }
      for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j] == 'Q') return false;
    }
    return true;
}

void print (char mat[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("|%c|", mat[i][j]);
        }
        printf("\n");
    }
        printf("\n");
}

void nqueens (char mat[][10], int r, int n) {
    if (r == n) {
        print(mat, n);
        return ;
    }
    for (int i = 0; i < n; i++) {
          if (isSafe(mat, r, i, n)) {
        mat[r][i] = 'Q';
        nqueens(mat, r + 1, n);
        mat[r][i] = ' ';
    }
    }
}

int main () {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    char mat[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = ' ';
        }
    }

    nqueens(mat, 0, n);
    return 0;
}