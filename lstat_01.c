#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;
    struct stat sObj;

    lstat("./lspl.txt", &sObj);

    printf("Inode number : %ld\n", sObj.st_ino);

    printf("Hardlink count : %ld\n", sObj.st_nlink);

    printf("Total size : %ld\n", sObj.st_size);

    printf("Block size : %ld\n", sObj.st_blksize);

    printf("File type is : %d\n", sObj.st_mode);

    return 0;
}
