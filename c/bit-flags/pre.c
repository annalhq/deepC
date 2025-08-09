#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int f(int x, bool is_added, bool is_squared, bool is_not){
  if (is_added) x += x;
  if (is_squared) x *= x;
  if (is_not) x = ~x;
  return x;
}

int main(int argc, char *argv[])
{
  printf("%d\n", f(1234, false, false, false));
  printf("%d\n", f(1234, true, false, false));
  printf("%d\n", f(1234, false, true, false));
  printf("%d\n", f(1234, false, false, true));

  return EXIT_SUCCESS;
}
