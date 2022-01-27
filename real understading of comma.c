//the comma operator (,) is used to separate two or more expressions that are included
// where only one expression is expected. When the set of expressions has to be evaluated
//  for a value, only the right-most expression is considered.

#include<stdio.h>
int main()
{ int a,b;
  a =( b=5,b++,b+3);
  printf("%d",a);
}
