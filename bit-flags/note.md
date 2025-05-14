# Bit Flags

Bit flags in C are a technique used to store multiple boolean options (true/false) efficiently in a single variable, using individual bits to represent each flag. This is especially useful when dealing with memory-constrained systems or needing fast bitwise operations.

The amount of states we can store inside one integer depends on it's memory size, for example a 64-bit integer can store 64 flag states at once.

In the `pre.c` the naive and more usual way to use booleans as a flag is shown.

Instead of using separate variables for each flag like 

```C
bool is_added = true;
bool is_squared = false;
bool is_not = true;
```
we can use one variable

```c
unsigned char style = 0b00000101 // is_added and is_not are set to true
```
Defining flags using variables

```c
#define is_added      0x01  // 00000001
#define is_squared    0x02  // 00000010
#define is_not        0x04  // 00000100
#define is_cubed      0x08  // 00001000
```

These are powers of 2, each represent one bit.

 Common operations:

```c
unsigned char style = 0; // lets say style is char variable holding our flags

style |= is_added; // set the is_added flag
style &= ~is_added; // clear a flag (turn a bit off)
style ^= is_added; // toggle the is_added flag

//check the flag
if (style & is_added){
  // is_added is set
}
```

In `bit.c` we have defined a bit flag type and three individual flags:

```c
typedef unsigned int t_flag;

#define FLAG_A (1 << 0)  // 0001 = 2^0 = 1
#define FLAG_B (1 << 1)  // 0010 = 2^1 = 2
#define FLAG_C (1 << 2)  // 0100 = 2^2 = 4
```

```c
int main(int argc, char *argv[])
{
  printf("%d\n", f(1234, 0));                        // No flags
  printf("%d\n", f(1234, FLAG_A));                   // FLAG_A only
  printf("%d\n", f(1234, FLAG_B | FLAG_C));          // FLAG_B and FLAG_C

  return EXIT_SUCCESS;
}
```
