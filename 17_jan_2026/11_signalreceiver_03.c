#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void MarvellousHandler(int iNo)
{
    printf("Marvellous Message - Signal arrived : %d\n", iNo);
}

int main(void)
{
    printf("PID is : %d\n", getpid());

    signal(SIGUSR1, MarvellousHandler);

    while (1)
    {
        sleep(1);
    }

    return 0;
}

