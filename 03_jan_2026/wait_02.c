#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(void)
{
    pid_t pid1 = 0;
    pid_t pid2 = 0;
    int status = 0;

    pid1 = fork();

    if (pid1 == 0)           // Child
    {
        sleep(10);
        exit(21);
    }

    pid2 = wait(&status);

    printf("Child with pid %d gets terminated with status %d\n", pid2, WEXITSTATUS(status));

    return 0;
}

