#include <stdio.h>

/* Exercise 1.13 Write a program to print a histogram of the lengths
   of words in its input. It is easy to draw the histogram with the
   bars horizontal; a vertical orientation is more challenging. */

#define  IN   1  /* inside word */
#define  OUT  0  /* outside word */

int main(void)
{
    int c, i, state, lword, nwords, index, g;
    int words[20];
    lword = nwords = index = g = 0;
    state = OUT;
  
    for (i = 0; i <= 20; ++i)
	words[i] = 0;

    while ((c = getchar()) != EOF) {
	if (c == '\n' || c == '\t' || c == ' ') {
	    state = OUT;
	    words[index - 1] = lword;
	} else if (state == OUT) {
	    lword = 0;
	    state = IN;
	    ++index;
	    ++lword;
	    ++nwords;
	} else {
	    ++lword;
	}
    }
    
    for (i = 0; i < 20; ++i) {
	if (words[i] > 0) {
	    printf("%3d ", words[i]);
	    for (int j = 0; j < words[i]; j++)
		printf("_");
	    printf("\n");
	}
    }
  
    for (i = 0; i < 20; ++i) {
	if (words[i] > g)
	    g = words[i];     
    }
    printf("\n\n");

    while (g > 0) {
	printf("%3d " , g);
	for (i = 0; i < 20; ++i) {
	    if (words[i] >= g)
		printf(" __ ");
	    else if (words[i] > 0)
		printf("    ");
	}
	--g;
	printf("\n");
    }
}
