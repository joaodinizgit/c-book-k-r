#include <stdio.h>
/* 1.19 Write a function reverse(s) that reverses the character string s.
   Use it to write a program that reverses its input a line at line. */

#define MAXCHAR 1000

int getln(char line[], int lim);
void r(char line[], char b[]);

int main(void)
{
    int len;
    char line[MAXCHAR];
    char b[MAXCHAR];
    
    while (len = getln(line, MAXCHAR) > 0) {
        r(line, b);
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

void r(char s[], char b[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
        ++i;            

    if (s[i - 1] == '\n') {
        for (j = 0; j < i - 1; j++) {
            b[j] = s[i - j - 2];
        }
        b[j] = '\n';
        b[j + 1] = '\0';
    } else {
        while ((b[j] = s[i - j - 1]) != '\0') {
            ++j;
        }
        s[j + 1] = '\0';
    }
    printf("%s", b);
}
