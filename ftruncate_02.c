#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>


int main(void)
{
    int iRet = 0;
    int fd = 0;

    fd = open("demo.txt", O_RDWR);

    iRet = ftruncate(fd, 5);

    if (iRet == 0)
    {
        printf("Truncate is successfull\n");
    }
    else
    {
        printf("There is issue in truncate call\n");
    }

    return 0;
}
