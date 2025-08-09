#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
  int a = 3;
  void *p = &a;

  printf("%p\n", p);
  // printf("%d\n", *p); // will give error as it does not know the datatype
  printf("%d\n", *(int*)p); // convert p to integer pointer

  return 0;
}
