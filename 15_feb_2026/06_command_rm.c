#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


//  ./rmx       FilePath
//  argv[0]     argv[1]
//  argc = 2

/*
    
*/


int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./rmx FilePath \n");
        return -1;
    }
    if (access(argv[1], F_OK) == -1)
    {
        printf("Error : There is no such file or directory\n");
        return -1;
    }

    if (unlink(argv[1]) < 0)
    {
        printf("Error : Unable to remove the file\n");
        return -1;
    }

    printf("File deleted successfully\n");
    
    return 0;
}

