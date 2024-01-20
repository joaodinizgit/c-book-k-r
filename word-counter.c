#include <stdio.h>

/* Exercise 1.11  */

#define  IN  1 /* inside a word */
#define  OUT 0 /* outside a word */

int main(void)
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
	++nc;
	if (c == '\n')
	    ++nl;
	if (c == ' ' || c == '\t' || c == '\n')
	    state = OUT;
	else if (state == OUT) {
	    state = IN;
	    ++nw;
	}
    }
    printf("Lines: %d\t Words: %d\t Characters: %d\n", nl, nw, nc);
}
			    
    
