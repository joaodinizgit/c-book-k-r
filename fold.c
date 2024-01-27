/* 1.22  Write a program to "fold" long input lines into two 
or more shorter lines after the last non-blank character
that occours before the n-th column of input. Make sure
your program does something intelligent with very long
lines, and if there are no blanks or tabs before the
epecified column.*/

#include <stdio.h>

#define C 12
#define L 3

int getln(char m[][C], int lim);

int main(void)
{
    char matrix[L][C];
    int i, j, len;
    len = 0;

    while ((len = getln(matrix, C)) > 0) {
        for (j = 0; j < L; ++j) {
            printf("FOLD %d: [%s]\n", j, matrix[j]);
        }

    }
}

// Fold the first 11 + '\0' characters in matrix
int getln(char m[][C], int lim)
{
    int c, i, j, k, x, y ;
    j = k = 0;

    for (x = 0; x < L; ++x){    
        for (y = 0; y < lim; ++y) {
            m[x][y] = '\0';             // Clean the matrix
        }
    }

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (k < lim - 2 && j < L) {
            m[j][k] = c;
            ++k;
        } else if (k == lim -2 && c != ' ' && c != '\t' && j < L) {     // only non-blank
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




