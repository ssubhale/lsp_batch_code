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

    fd = open("hole.txt", O_RDONLY | O_WRONLY | O_CREAT, 0777);

    if (fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n", fd);

    iRet = lseek(fd, 4100, SEEK_SET);

    printf("Current offset is : %d\n", iRet);

    iRet = write(fd, "END", 3);

    printf("%d bytes gets successfully write\n", iRet);

    close(fd);

    return 0;
}
