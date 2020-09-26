#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct proc {
        char name[16];
        int procstate;
        int inode;
    };

    struct proc* p = NULL;

    p = (struct proc*)
        malloc(sizeof(struct proc));

    p->procstate = 42;

    printf("proc 0 at address %p, state = %d\n", p, p->procstate);
}