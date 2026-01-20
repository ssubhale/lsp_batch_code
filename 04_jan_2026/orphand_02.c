#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    pid_t pid = 0;

    pid = fork();

    if (pid == 0)       // Child
    {
        printf("Child process is running...\n");
        printf("PID of child id %d & PPID of child is %d\n", getpid(), getppid());
        sleep(20);
        printf("PID of child id %d & PPID of child is %d\n", getpid(), getppid());
        exit(0);
    }
    else                // Parent
    {
        printf("Parent process is running...\n");
        printf("PID of parent id %d & PPID of parent is %d\n", getpid(), getppid());
        exit(1);
    }

    return 0;
}

