#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    pid_t childPid = 0;
    pid_t iResult = 0;

    int status = 0;
    
    childPid = fork();

    if (childPid == 0)
    {
        printf("Child is running with pid %d\n", getpid());
        sleep(10);
        printf("Child process exiting\n");
        exit(11);
    }
    else
    {
        printf("Parent is running...\n");

        printf("Parent is wating for child : %d\n", childPid);

        iResult = waitpid(childPid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("Child exited with pid : %d\n", iResult);
            printf("Exit status of child is : %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

