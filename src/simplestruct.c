#include <stdio.h>

int main()
{
    struct proc {
        char name[16];
        int procstate;
        int inode;
    } proc[1024];

    proc[0].procstate = 3 ;
    proc[1].procstate = 4 ;

    printf("proc 1 state = %d\n", proc[0].procstate);
    printf("proc 2 state = %d\n", proc[1].procstate);
}