#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


//  ./statx    file_name
//  argv[0]      argv[1]
//  argc = 2

/*
    Accept file name from command line
    Call access() to check the existence of the file
    Call stat system call to get the metadata of file
    Display the metadata
*/


int main(int argc, char * argv[])
{
    struct stat sObj;
    int iRet = 0;

    if (argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./statx fileName \n");
        return -1;
    }

    if (access(argv[1], F_OK) == 0)
    {
        iRet = stat(argv[1], &sObj);
        if (iRet < 0)
        {
            printf("Error : Unable to fetch statical inforamtion\n");
            return -1;
        }

        printf("File name : %s\n", argv[1]);
        printf("File size : %ld\n", (long)sObj.st_size);
        printf("Inode number : %ld\n", (long)sObj.st_ino);
    }
    else
    {
        printf("Error : There is no such file or directory\n");
        return -1;
    }

    return 0;
}

