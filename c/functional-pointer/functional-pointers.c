#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int foo(int x, int y){
     return x + y;
}
/* 
1. function itself when we refernce it, is a mem where their is bin code
2. above fucntion type is int (*)(int, int)

*/

bool p(int x){
     return x % 2 == 0;
}

void print_if(int xs[10], bool (*predicate)(int)){
     for (int i = 0; i < 10; i++){
          if (predicate(xs[i])){
               printf("%d\n", xs[i]);
          }
     }
}

int compar(const void *x1, const void *x2)
{
     return (*(int*)x2) - (*(int*)x1);
}

int main(void){
     int xs[] = {1, 3, 2, 4, 8, 6, 7, 5, 9, 10};

     // int (*f)(int, int) = foo; // function pointer
     
     // printf("%d\n", f(1, 2));

     // print_if(xs, p); // passing function pointer to another function
     for (int i = 0; i < 10; i++)
     {
          printf("%d\n", xs[i]);
     }
     printf("-------------\n");

     qsort(xs, 10, sizeof(int), compar);
     for (int i = 0; i < 10; i++){
          printf("%d\n", xs[i]);
     }

     return 0;
}