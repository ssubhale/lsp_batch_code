#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// ./mvx    OldPath     NewPath
// argv[0]  argv[1]        argv[2]

// argc = 3

/*
    Rename the file using the rename() system call
*/


int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./mvx OldPath NewPath\n");
        return -1;
    }

    if (rename(argv[1], argv[2]) < 0)
    {
        printf("Error : Unable to move\n");
        return -1;
    }

    return 0;
}

