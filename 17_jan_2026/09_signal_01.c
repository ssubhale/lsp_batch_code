#include <stdio.h>
#include <unistd.h>


int main(void)
{
    printf("PID is : %d\n", getpid());

    while (1)
    {
        sleep(1);
    }

    return 0;
}


//  kill -SIGINT 9864           // kill the process by the command
