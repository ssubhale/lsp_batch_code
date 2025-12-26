#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    char path[100];
    int iRet = 0;

    memset(path, '\0', sizeof(path));

    iRet = readlink("./test_applications/lspl.txt", path, sizeof(path));

    if (iRet == -1)
    {
        printf("There is an error %s\n", strerror(errno));
        return -1;
    }
    
    path[iRet] = '\0';
    
    printf("Data from readlink is : %s\n", path);

    return 0;
}

