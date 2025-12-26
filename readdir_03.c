#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir("./data_applications");

    if (NULL == dp)
    {
        printf("Unable to open directory %s\n", strerror(errno));
        return -1;
    }

    while (ptr = readdir(dp))
    {
        // fd = open() => read()
        // print include workd count
    }

    closedir(dp);
    
    return 0;
}

