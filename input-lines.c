#include <stdio.h>
/* 1.18 Write a program to print all input lines that are longer than 80
   characters. */
#define MAXCHAR 1000
int getln(char line[], int max);

int main(void)
{
    int len;
    char line[MAXCHAR];
    while ((len = getln(line, MAXCHAR)) > 0) {
        if (len > 80) {
            printf("Chars: %d, %s", len, line);
        }
    }
    return 0;
}

int getln(char s[], int lim)
{
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j] = c;
            ++j
        }
    }
    if (c == '\n' && j < lim - 1) {
        s[j] = c;
        s[j+1] = '\0';
        ++i;
    } else if (c == '\n') {
        s[j+1] = '\0';
        ++i;
    }
    return i;
}
