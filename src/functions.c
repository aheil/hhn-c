# #include <stdio.h>

long f(long x)
{
    long y = x * 2;
    return y;
} 

long g (long x)
{
    long y = x + 1;
    return y; 
}

int main(int argc, char* argv[])
{
    long x = (long) argv[1];
    long y = g(f(x));

    printf("%ld\n", y);
}