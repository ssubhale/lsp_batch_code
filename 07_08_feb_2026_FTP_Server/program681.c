#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    int iReturn = 0;

    iReturn = fork();

    if (iReturn == 0)
    {
        printf("Child process is running with PID : %d\n", getpid());
    }
    else
    {
        printf("Parent process is running with PID : %d\n", getpid());
        printf("PID of child is %d\n", iReturn);
    }

    return 0;
}