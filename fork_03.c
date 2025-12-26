#include <stdio.h>
#include <unistd.h>


int main(void)
{
    pid_t pid = 0;

    pid = fork();

    if (pid == 0)
    {
        printf("CHILD SAYS : PID of current process : %d, PID of parent : %d, Return value of fork() %d\n", getpid(), getppid(), pid);
    }
    else
    {
        printf("CHILD SAYS : PID of current process : %d, PID of parent : %d, Return value of fork() %d\n", getpid(), getppid(), pid);

    }
    return 0;
}
