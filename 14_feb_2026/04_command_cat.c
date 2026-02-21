#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

//  ./catx    file_name
//  argv[0]      argv[1]
//  argc = 2

/*
    Accept file name from command line
    Check whether exists or not
    If it existing print on console
    If it not existing 
    Display No such file or directory
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc, char * argv[])
{
    int fd = 0;
    char chBuffer[MAX_BUFFER_SIZE] = {'\0'};
    int iRet = 0;

    if (argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./catx fileName \n");
        return -1;
    }

    if (access(argv[1], F_OK) != 0)
    {
        printf("catx: %s: No suxh file or directory\n", argv[1]);
        return -1;
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            printf("Error : Unable to open file\n");
            printf("Error : %s\n", strerror(errno));
            return -1;
        }

        while ((iRet = read(fd, chBuffer, sizeof(chBuffer))) != 0)
        {
            write(1, chBuffer, iRet);
        }
    }

    return 0;
}

