# Functional Pointers

`foo` is pointer to function that takes two `int` args and returns an `int`.

**PREDICATE FUNCTIONS:** Those who return a single TRUE or FALSE 

`print_if` is HIGHER ORDER function

## qsort

```c
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

## REF

1. [qsort_r LINUX Man page](https://linux.die.net/man/3/qsort_r)