/* 1.21 Write a program entab that replaces strings of blanks
   by the minimum number of tabs and blanks to achieve the same spacing.
   Use the same tab stops as for detab. When either a tab
   or a single blank would suffice to reach a tab stop,
   which should be given preference? */

#include <stdio.h>

#define TAB 8

int main(void)
{
    int c, i, s, column, t;
    s = column = t = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (s == 0)
                s = TAB - (column % TAB); // min. spaces to change to tab
            ++t;
            if (t == s) {
                putchar('\t');
                s = 0;
                t = 0; 
            }
            ++column;
        } else if (c == '\n') {
            putchar(c);
            s = 0;
            t = 0;
            column = 0;
        } else {
            for (i = 0; i < t; ++i)
                putchar(' ');
            putchar(c);
            s = 0;
            t = 0;
            ++column;
        }
    }
}
