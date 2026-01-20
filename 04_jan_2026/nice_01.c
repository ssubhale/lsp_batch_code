#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>


int main(void)
{
    int iResult = 0;

    iResult = nice(0);

    printf("Current nice value is %d\n", iResult);

    return 0;
}

