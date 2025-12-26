#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    char path[100];
    int iRet = 0;
    int fd = 0;
    char arr[20];

    memset(path, '\0', sizeof(path));
    memset(arr,'\0', sizeof(arr));

    iRet = readlink("./test_applications/lspl.txt", path, sizeof(path));

    if (iRet == -1)
    {
        printf("There is an error %s\n", strerror(errno));
        return -1;
    }
    
    path[iRet] = '\0';
    
    printf("Data from readlink is : %s\n", path);

    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file %s\n", strerror(errno));
        return -1;
    }

    read(fd, arr, 10);

    printf("Data from original file %s\n", arr);

    close(fd);

    return 0;
}

