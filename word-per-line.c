#include <stdio.h>

/* Exercise 1.12 - Write a program that prints its input one word
   per line. */

#define  IN  1  /* inside a word */
#define  OUT 0  /* outside a word */

int main(void)
{
    int c, w, state;
    state = OUT;

    while ((c = getchar()) != EOF) {
	if (c != ' ' && c != '\n' && c != '\t') {
	    printf("%c", c);
	    state = IN;
	} else if (state == IN) {
	    printf("\n");
	    state = OUT;
	}
    }
    printf("\n");
}
