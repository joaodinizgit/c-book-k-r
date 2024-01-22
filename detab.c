/* 1.20 Write a program "detab" that replaces tabs in the input
   with the proper number of blanks to space to the next tab
   stop. Assume a fixed set of tab stop, say every n columns.
   Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define MAXCHAR 1000
#define TAB 4

int getln(char s[], int lim);
void t(char from[], char to[], int t);

int main(void)
{
    int len;
    char line[MAXCHAR];
    char b[MAXCHAR];

    while ((len = getln(line, MAXCHAR)) > 0) {
        t(line, b, TAB);
        printf("%s", b);
    }
}

int getln(char s[], int lim)
{
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim -1) {
	    s[j] = c;
	    ++j;
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

void t(char from[], char to[], int t)
{
    int i, j, k;
    k = 0;
    for (i = 0; from[i] != '\0'; ++i) {
        if (from[i] == '\t') {
            for (j = 0; j < t; ++j) {
                to[k] = ' ';
                ++k;
            }
        } else {
            to[k] = from[i];
            ++k;
        }
    }
    to[k] = '\0';
}
