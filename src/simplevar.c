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

    printf("static s = %d\n", s++);
    printf("local  n = %d\n", n++);

    foo();
}