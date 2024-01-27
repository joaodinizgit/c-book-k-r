/* 1.22  Write a program to "fold" long input lines into two 
or more shorter lines after the last non-blank character
that occours before the n-th column of input. Make sure
your program does something intelligent with very long
lines, and if there are no blanks or tabs before the
epecified column.*/

#include <stdio.h>

#define C 7  // number of columns(with '\0')
#define L 3  // three folds

int getln(char m[][C], int lim);

int main(void)
{
    char matrix[L][C];
    int i, j, len;

    while ((len = getln(matrix, C)) > 0) {
        for (j = 0; j < L; ++j) {
            printf("FOLD %d: [%s]\n", j, matrix[j]);
        }
    }
}

int getln(char m[][C], int lim)     // fold elements
{
    int c, i, j, k, x, y, b ;
    j = k = b = 0;

    for (x = 0; x < L; ++x){        // clean matrix
        for (y = 0; y < lim; ++y) {
            m[x][y] = '\0';
        }
    }

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {     // start to fold
        if (k < lim - 2 && j < L && b == 0) {
            m[j][k] = c;
            ++k;
        } else if (c != ' ' && c != '\t' && j < L) {     // only non-blank
            m[j][k] = c;
            ++k;
            m[j][k] = '\0';
            ++j;
            k = 0;
        }
    }

    if (c == '\n' && k < lim - 1){
        m[j][k] = c;
        m[j][k+1] = '\0';
        ++i;
    } else if (c == '\n') {
        m[j][k] = '\0';
        ++i;
    }
    return i;
}






