#include <stdio.h>

/* 1.14 Write a program to print a histogram of the
   frequencies of different characters in its input. */

#define INDEXES 128

int main(void)
{
    int c, i, g;
    int at[INDEXES];
    g = 0;

    for (i = 0; i <= INDEXES; ++i)
	at[i] = 0;

    while ((c = getchar()) != EOF)
	++at[c];

    for (i = 0; i < INDEXES; ++i){
	if (at[i] > 0)
	    if (i == '\n')
		printf(" \\n = %d ",  at[i]);
	    else if (i == ' ')
		printf(" spaces: %d ",  at[i]);
	    else if (i == '\t')
		printf(" \\t = %d ", i, at[i]);
	    else
		printf(" %c = %d ", i, at[i]);
    }
    printf("\n\n");

    for (i = 0; i < INDEXES; ++i){
	if (at[i] > g)
	    g = at[i];
    }

    while (g > 0) {
	printf("%3d ", g);
	for (i = 0; i < INDEXES; ++i) {
	    if (at[i] >= g)
		printf(" _ ");
	    else if (at[i] > 0)
		printf("   ");
	}
	--g;
	printf("\n");
    }
    printf("\n");
}
