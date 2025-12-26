#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int fd = 0;

    fd = open("demo.txt", O_RDONLY);
    
    printf("Value of fd is : %d\n", fd);

    if (errno != 0)
    {
        printf("Value of errno is : %d\n", errno);
        printf("Error statement : %s\n", strerror(errno));
    }

    return 0;
}
