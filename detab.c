/* 1.20 Write a program "detab" that replaces tabs in the input
   with the proper number of blanks to space to the next tab
   stop. Assume a fixed set of tab stop, say every n columns.
   Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define TAB 8

int main(void)
{
    int i, c, p;
    p = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < TAB - p; ++i)
                putchar(' ');
            p = 0;
        } else if (c == '\n') {
            putchar(c);
            p = 0;
        } else {
            putchar(c);
            ++p;
        }
        if (p >= TAB)
            p = 0;
    }
}
