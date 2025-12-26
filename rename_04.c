#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int iRet = 0;
    int fd = 0;
    char arr[50];

    fd = open("./process.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    iRet = rename("./process.txt", "./test_applications/hello.txt");

    if (iRet == 0)
    {
        printf("File renamed successfully\n");
    }
    else
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    iRet = read(fd, arr, 50);
    if (iRet != 0)
    {
        printf("Data from file is %s", arr);
    }

    close(fd);

    return 0;
}
