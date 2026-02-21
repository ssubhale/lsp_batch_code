#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    __pid_t iPid = 0;

    iPid = fork();

    if (iPid < 0)
    {
        printf("Unable to create the child process\n");
        return -1;
    }

    if (iPid == 0)
    {
        printf("Child process gets created successfully\n");

    }

    return 0;
}

