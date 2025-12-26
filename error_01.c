#include <stdio.h>
#include <errno.h>

int main(void)
{
    printf("Demonstration of errno\n");
    printf("%d\n", errno);

    return 0;
}
