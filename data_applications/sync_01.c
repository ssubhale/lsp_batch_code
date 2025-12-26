#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    int fd = 0;

    char chBuffer[] = "indiaismycountry";
    
    int iRet = 0;

    fd = open("demo.txt",O_CREAT | O_WRONLY | O_APPEND, 0777);      // Important

    if (fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n", fd);

    iRet = write(fd, chBuffer, 16);

    printf("%d bytes gets successfully writen\n", iRet);

    close(fd);

    return 0;
}
