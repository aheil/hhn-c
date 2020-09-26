#include <stdio.h>

int main()
{

    int procstate[1024];

    procstate[0] = 2;
    procstate[1] = 3;

    printf("proc 1 state = %d\n", procstate[0]);
    printf("proc 2 state = %d\n", procstate[1]);

}