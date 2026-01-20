#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


int main(void)
{
    int fd = 0;
    int iRet = 0;
    int iCount = 0;
    int iCounter = 0;
    char chBuffer[BUFFER_SIZE] = {'\0'};

    fd = open("ppa.txt", O_RDONLY);

    while ( (iRet = read(fd, chBuffer, BUFFER_SIZE)) > 0 )
    {
        for (iCounter = 0; iCounter < iRet; iCounter++)
        {
            if ((chBuffer[iCounter] >= 'A') && (chBuffer[iCounter] <= 'Z'))
            {
                iCount++;
            }
        }
    }

    close(fd);

    printf("Number of capital letters : %d\n", iCount);

    return 0;
}

