#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

// ./lsx
// argv[0]

// argc = 1

/*
    Open the current directory (".")
    Read all entries from that directory
    Print the name of files
    Close the directory
*/


int main(void)
{
    char * chPath = ".";
    DIR * dp = NULL;
    int iRet = 0;

    dp = opendir(chPath);

    if (dp == NULL)
    {
        printf("Error : Unable to open directory\n");
        return -1;
    }

    struct dirent *dObj;

    while ((dObj = readdir(dp)) != NULL)
    {
        printf("%s\n", dObj -> d_name);
    }

    closedir(dp);

    return 0;
}

