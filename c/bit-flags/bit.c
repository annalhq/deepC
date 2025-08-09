#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// typedef unsigned int t_flag;
// #define FLAG_A (1 << 0)
// #define FLAG_B (1 << 1)
// #define FLAG_C (1 << 2)

typedef enum {
  FLAG_A = (1 << 0),
  FLAG_B = (1 << 1),
  FLAG_C = (1 << 2)
} t_flag ;

int f(int x, t_flag flags){
  if (flags & FLAG_A){
    x += x;
    flags &= ~FLAG_A;
  };

  if (flags & FLAG_B) x *= x;
  if (flags & FLAG_C) x = ~x;
  return x;
}

int main(int argc, char *argv[])
{
  printf("%d\n", f(1234, 0));
  printf("%d\n", f(1234, FLAG_A));
  printf("%d\n", f(1234, FLAG_B | FLAG_C));

  return EXIT_SUCCESS;
}
