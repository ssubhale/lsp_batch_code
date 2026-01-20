#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    pid_t pid1 = 0;
    pid_t pid2 = 0;

    printf("Main process start\n");

    pid1 = fork();

    if (pid1 == 0)
    {
        execl("./capprocess.exe", "", NULL);
    }
    else
    {

    }

    pid2 = fork();

    if (pid2 == 0)
    {
        execl("./smallprocess.exe", "", NULL);
    }
    else
    {

    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("End Main process\n");

    return 0;
}

