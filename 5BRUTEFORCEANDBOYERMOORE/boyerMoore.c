#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void badCharHeuristic (char *pattern, int size, int heruristic[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        heruristic[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        heruristic[(int)pattern[i]] = 1;
    }
}

void boyerMooreSearch (char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int heruristic[NO_OF_CHARS];

    badCharHeuristic(pattern, m, heruristic);

    int s = 0;
    while (s < (n + m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            printf("Found att %d", s);
            s+= s + m < n ? (m- heruristic[text[s + m]]) : 1;
        } else {
            int shift = j - heruristic[text[s + j]];
            s += (shift > 1) ? shift : 1;
        }
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
    boyerMooreSearch(text, pattern);

    return 0;
}