#include <stdio.h>
/* 1.18 Write a program to remove trailing blanks and tabs from each line
   of input, and to delete entirely blank lines. */
#define MAXCHAR 1000

int getln(char line[], int max);
void rtb(char line[]);
void rtab(char line[]);
int bl(char line[]);

char line[MAXCHAR];
char b[MAXCHAR];
int len;

int main(void)
{
    while ((len = getln(line, MAXCHAR)) > 0) {
        if (bl(line) > 0) {           
            rtab(line);
            rtb(b);
            printf("%s", b);
        }
    }
}

int getln(char s[], int lim)
{
    int i, j, c;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n' && j < lim - 1) {
        s[j] = c;
        s[j + 1] = '\0';
        ++i;
    } else if (c == '\n') {
        s[j] = '\0';
        ++i;
    }
    return i;
}

/* Check for entirely blank line */
int bl(char line[])
{
    int i, j;
    i = j = 0;
    while (line[i] != '\0'){
        if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
            ++j;
        ++i;
    }
    return j;
}

/* Remove trailing blanks */
void rtb(char line[])
{
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '\n' && line[i - 1] == ' ') {
            line[i - 1] = '\n';
            line[i] = '\0';
            rtb(line);
        }
        ++i;
    }
}

/* Remove tabs */
void rtab(char line[])
{
    int i, j;
    i = j = 0;
    while (line[i] != '\0') {
        if (line[i] != '\t') {
            b[j] = line[i];
            ++j;
        }
        ++i;
    }
    b[j] = '\0';
}
