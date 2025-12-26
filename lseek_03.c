#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define SIZE_BUFFER 100


int main(void)
{
    int fd = 0;

    char chBuffer[SIZE_BUFFER] = {'\0'};
    
    int iRet = 0;

    memset(chBuffer, '\0', SIZE_BUFFER);

    fd = open("demo.txt", O_RDONLY);

    if (fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n", fd);

    iRet = read(fd, chBuffer, 10);

    memset(chBuffer, '\0', SIZE_BUFFER);

    iRet = lseek(fd, 5, SEEK_CUR);

    printf("Updated file offset is %d\n", iRet);
    
    iRet = read(fd, chBuffer, 11);

    printf("Data from file is : %s\n", chBuffer);

    close(fd);

    return 0;
}
