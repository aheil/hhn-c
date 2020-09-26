#include <stdio.h>

int main()
{
    struct proc {
        char name[16];
        int procstate;
        int inode;
    } proc[1024];

    proc[0].procstate = 3 ;

    printf("proc 0  at address %p, state = %d\n", &proc[0], (&proc[0])->procstate);
}