#include <stdio.h>

/* Line Counting */
int main() {
  int c, nl, blanks, tabs;
  blanks = 0;
  tabs = 0;
  nl = 0;
  while ((c = getchar()) != EOF){
    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++tabs;
    if (c == ' ')
      ++blanks;
  }
  
  printf("%d\n%d\t%d\n", nl, tabs, blanks);
}
