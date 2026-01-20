#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int iResult = 0;

    iResult = nice(0);

    printf("Current nice value is %d\n", iResult);

    iResult = nice(-5);         // Increase priority
    if (iResult == -1)
    {
        printf("Error : %s\n", strerror(errno));
    }

    printf("Current nice value is %d\n", iResult);

    return 0;
}

