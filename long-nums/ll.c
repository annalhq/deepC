#include <stdio.h>

int main()
{
  // digit separators
  long x = 1'000'000'000; // 1 billion
  unsigned long hex = 0xFF'FF'FF'FF; // max hex value for 32-bit unsigned int
  
  printf("%ld\n", x);
  printf("%lu\n", hex);
  return 0;
}
