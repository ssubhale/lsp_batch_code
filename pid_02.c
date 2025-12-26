#include <stdio.h>
#include <unistd.h>


int main(void)
{

    printf("PID of parent process is : %d\n", getppid());

    printf("PID of current proceess is : %d\n", getpid());

    return 0;
}
