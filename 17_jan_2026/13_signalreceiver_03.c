#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void MarvellousHandler(int iNo)
{
    if (iNo == SIGUSR1)
    {
        printf("Marvellous Message - SIGUSR1 arrived : %d\n", iNo);
    }
    else if (iNo == SIGINT)
    {
        printf("Marvellous Message - SIGINT arrived : %d\n", iNo);
    }
}


int main(void)
{
    printf("PID is : %d\n", getpid());

    signal(SIGUSR1, MarvellousHandler);
    signal(SIGINT, MarvellousHandler);

    while (1)
    {
        sleep(1);
    }

    return 0;
}

