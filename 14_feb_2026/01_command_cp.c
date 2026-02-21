#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// ./cpx    source_file     destination_file
// argv[0]  argv[1]         argv[2]

// argc = 3

/*
    Open Source file for reading
    Create Destination file
    Read the data from Source file
    Write it insto destion file
    close both files
*/

#define MAX_BUFFER_SIZE 1024


int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./cpx SourceFileName DestinationFileName\n");
        return -1;
    }

    int fdSource = 0;
    int fdDestionation = 0;
    int iRet = 0;

    char chBuffer[MAX_BUFFER_SIZE] = {'\0'};

    memset(chBuffer, '\0', sizeof(chBuffer));

    fdSource = open(argv[1], O_RDONLY);

    if (fdSource < 0)
    {
        printf("Error : Unable to open source file %s\n", argv[1]);
        return -1;
    }

    fdDestionation = creat(argv[2], 0777);

    if (fdDestionation < 0)
    {
        printf("Error : Unable to create the destination file %s\n", argv[2]);
        close(fdSource);
        return -1;
    }

    while ((iRet = read(fdSource, chBuffer, sizeof(chBuffer))) != 0)
    {
        write(fdDestionation, chBuffer, iRet);
        memset(chBuffer, '\0', sizeof(chBuffer));
    }

    printf("Success : Copy activity done\n");

    close(fdSource);
    close(fdDestionation);

    return 0;
}

