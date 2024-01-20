#include <stdio.h>

/* 1.15 Rewrite the temperature conversion program of section 1.2
   to use a function for conversion. */

#define LOWER  0
#define UPPER  300
#define STEP   20

float conv(float fahr);

int main(void)
{
    float f;

    f = LOWER;
    while (f <= UPPER) {
	printf("%3.0f %6.1f\n", f , conv(f));
	f += STEP;
    }
}

float conv(float f)
{
    return (5.0/9.0)*(f-32);
}
