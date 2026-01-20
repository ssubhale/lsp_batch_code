#include <stdio.h>


void Demo(int *ptr)
{
    *ptr = 11;
}

int main(void)
{
    int iNo = 0;

    Demo(&iNo);

    printf("Return value is : %d\n", iNo);

    return 0;
}

