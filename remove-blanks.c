#include <stdio.h>

/* Exercise 1.9 Write a program to copy its input to
   its output, replace each string of one or more blanks by a single
   blank. */

int main(void)
{
    int input, b;
    b = 0;
  
    while((input = getchar()) != EOF) {
	if (input == ' ')
	    ++b;
	else
	    b = 0;

	if (b > 1)
	    input = 0 ;
	
	putchar(input);
    }
}
