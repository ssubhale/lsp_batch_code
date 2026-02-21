#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

// ./lsx        -i
// argv[0]      argv[2]

// argc = 2

/*
    Open the current directory (".")
    Read all entries from that directory
    Print the name of files
    Close the directory
*/

int main(int argc, char *argv[])
{
    int iOption = 0;
    // 1 : ls -a
    // 2 : ls -i

    if (argc == 1)
    {
        iOption = 1;
    }
    else if (strcmp(argv[1], "-a") == 0)
    {
        iOption = 1;
    }
    else if (strcmp(argv[1], "-i") == 0)
    {
        iOption = 2;
    }
    else
    {
        printf("There is no such option\n");
        return -1;
    }

    char *chPath = ".";
    DIR *dp = NULL;
    int iRet = 0;

    dp = opendir(chPath);

    if (dp == NULL)
    {
        printf("Error : Unable to open directory\n");
        return -1;
    }

    struct dirent *dObj;

    if (iOption == 1)
    {
        while ((dObj = readdir(dp)) != NULL)
        {
            printf("%s\n", dObj -> d_name);
        }
    }

    else if (iOption == 2)
    {
        while ((dObj = readdir(dp)) != NULL)
        {
            printf("%ld\t%s\n", dObj -> d_ino, dObj -> d_name);
        }
    }

    closedir(dp);

    return 0;
}
