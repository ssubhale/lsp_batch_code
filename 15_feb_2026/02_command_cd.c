#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

//  ./cdx       Directory_Path
//  argv[0]     argv[1]
//  argc = 2

/*
    Accept new directory path
    Call chdir() with that path
    Call getcwd() to check the change path 
*/


int main(int argc, char * argv[])
{
    int iRet = 0;
    char chBuffer[1024] = {'\0'};

    if (argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./cdx Directory_Path \n");
        return -1;
    }

    iRet = chdir(argv[1]);

    if (iRet < 0)
    {
        printf("Error : Unable to change directory\n");
        printf("Error : %s\n", strerror(errno));
    }

    getcwd(chBuffer, sizeof(chBuffer) -1);

    printf("Current directory change to %s\n", chBuffer);

    return 0;
}

