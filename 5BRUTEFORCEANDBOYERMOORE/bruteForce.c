#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void bruteForce (const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int found = 0;

    for (int i = 0; i < n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Fouond at %d", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Not Found");
    }
}

int main () {
    char *text[100], *pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Enter the text: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    bruteForce(text, pattern);
    return 0;
}