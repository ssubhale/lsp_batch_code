#include <stdio.h>
#include <unistd.h>


int main(void)
{
    pid_t pid = 0;

    pid = fork();

    printf("PID of current process : %d, PID of parent %d, Return value of fork %d\n", getpid(), getppid(), pid);

    return 0;
}
