struct B
{
};
struct C
{
};

struct S : B, C
{
     int j;
};

int main()
{
     return sizeof(S);
}