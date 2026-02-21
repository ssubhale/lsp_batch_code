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

void DisplayPermission(mode_t iMode)
{
    char Arr[10] = "----------";

    if (S_ISDIR(iMode)) Arr[0] = 'd';
    if (S_ISLNK(iMode)) Arr[0] = 'l';

    // Regular file permissions
    
    if (iMode & S_IRUSR) Arr[1] = 'r';

    if (iMode & S_IWUSR) Arr[2] = 'w';

    if (iMode & S_IXUSR) Arr[3] = 'x';

    
    if (iMode & S_IRGRP) Arr[4] = 'r';

    if (iMode & S_IWGRP) Arr[5] = 'w';

    if (iMode & S_IXGRP) Arr[6] = 'x';


    if (iMode & S_IROTH) Arr[7] = 'r';

    if (iMode & S_IWOTH) Arr[8] = 'w';

    if (iMode & S_IXOTH) Arr[9] = 'x';

    printf("File permision : %s\n", Arr);
}


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

        DisplayPermission(sObj.st_mode);

    }
    else
    {
        printf("Error : There is no such file or directory\n");
        return -1;
    }

    return 0;
}

