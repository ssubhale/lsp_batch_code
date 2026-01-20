#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(void)
{
    int pid = 0;

    printf("Enter PID of process : \n");
    scanf("%d", &pid);

    kill(pid, SIGUSR1);

    return 0;
}

