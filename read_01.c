#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    int fd = 0;

    char chBuffer[100] = {'\0'};
    
    int iRet = 0;

    fd = open("demo.txt", O_RDONLY);

    if (fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n", fd);

    iRet = read(fd, chBuffer, 10);

    printf("%d bytes gets successfully read\n", iRet);

    printf("Data from file : %s", chBuffer);

    close(fd);

    return 0;
}
