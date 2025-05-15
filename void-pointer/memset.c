#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

void *my_memset(void *data, uint8_t c, size_t n)
{
  uint8_t *data_as_bytes = (uint8_t*)data;

  for (size_t i = 0; i < n; i++)
  {
    data_as_bytes[i] = c;
  }
  return data;
}

int main(void)
{
  int xs[5] = {1, 2, 3, 4, 5};
 
  for (int i = 0; i < 5; i++)
    printf("%d ", xs[i]);
  printf("\n");

  my_memset(xs, 1, sizeof xs);
 
  for (int i = 0; i < 5; i++)
    printf("%d ", xs[i]);
  printf("\n");

  return 0;
}
