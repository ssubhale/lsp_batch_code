#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;
    struct stat sObj;

    stat("demo.txt", &sObj);

    printf("Inode number : %ld\n", sObj.st_ino);

    printf("Hardlink count : %ld\n", sObj.st_nlink);

    printf("Total size : %ld\n", sObj.st_size);

    printf("Block size : %ld\n", sObj.st_blksize);

    printf("File type is : %d\n", sObj.st_mode);

    if (S_ISBLK(sObj.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISCHR(sObj.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISDIR(sObj.st_mode))
    {
        printf("Directory fiele");
    }
    else if (S_ISREG(sObj.st_mode))
    {
        printf("Reguler file\n");
    }
    else if (S_ISSOCK(sObj.st_mode))
    {
        printf("Sock file\n");
    }
    else if (S_ISFIFO(sObj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if (S_ISLNK(sObj.st_mode))
    {
        printf("Symbolic link\n");
    }

    return 0;
}
