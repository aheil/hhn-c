#include <stdio.h>

void foo();

int main()
{
    foo();
}

void foo()
{
    static int s;
    int n;

    int *s_ptr;
    int *n_ptr;

    s_ptr = &s;
    n_ptr = &n;

    printf("static s = %d, address =%p\n", s++, s_ptr);
    printf("local  n = %d, address =%p\n", n++, n_ptr);

    foo();
}