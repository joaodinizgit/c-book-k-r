#include <stdio.h>
/* Print the longest input line */

#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getln(line, MAXLINE)) > 0){
	printf("%d, string: %s", len, line);
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    }
 	if (max > 0)
	    printf("LONGEST: %d, %s\n", max, longest);
	return 0;
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

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}

