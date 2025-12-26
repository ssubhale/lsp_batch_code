#include <stdio.h>
#include <unistd.h>


int main(void)
{
    __pid_t pid = 0;

    pid = fork();

    if (pid == 0)
    {
        printf("CHILD SAYS : PID of current process : %d, PID of parent %d, Return value of fork %d\n", getpid(), getppid(), pid);
        execl("./commandline.exe", "", NULL);
    }
    else
    {
        printf("PARENT SYS : PID of current process : %d, PID of parent %d, Return value of fork %d\n", getpid(), getppid(), pid);
    }

    return 0;
}
