#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>


int main(void)
{
    DIR *dp = NULL;

    dp = opendir("./data_applications");

    if (NULL == dp)
    {
        printf("Unable to open directory %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("Directory open successfully\n");
    }

    closedir(dp);
    
    return 0;
}

