# Empty Base Optimization (EBO)

Empty base optimization is commonly used by allocator-aware standard library classes (std::vector, std::function, std::shared_ptr, etc) to avoid occupying any additional storage for its allocator member if the allocator is stateless. This is achieved by storing one of the required data members (e.g., begin, end, or capacity pointer for the vector) in an equivalent of boost::compressed_pair with the allocator. 


```cpp
struct S {};

//objects must have unique addresses
int main()
{
     return sizeof(S);
}
```

asm output for this is 

```assembly
main:
        mov     eax, 1
        ret
```

Another rule for standard-layout types is that the first data member of a struct has the same address as the struct itself.

Similarly, with standard-layout inheritance, the address of the base class subobject is the same as the address of the derived object.

```cpp
struct B {
    int i;
};

struct S : B {
    int j;
};

int main()
{
     return sizeof(S);
}
```

returns 

```assembly
main:
        mov     eax, 8
        ret
```

memmap: 4(int i)->4(int j) whereas in following code

```cpp
struct B {};
struct C {};

struct S : B, C {
    int j;
};

int main()
{
     return sizeof(S);
}
```

returns 

```assembly
main:
        mov     eax, 4
        ret
```

so EBO: base classes are collapsed down if they are empty so that it optimized the obj layout

### refs

1. [[[no_unique_address]]](https://en.cppreference.com/w/cpp/language/attributes/no_unique_address)
2. see EBO usecases in [Policy based design](http://en.wikipedia.org/wiki/Policy-based_design)
3. [lsu ebo](http://ld2016.scusa.lsu.edu/cppreference/en/cpp/language/ebo.html)