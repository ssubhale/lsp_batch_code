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

    ptr = readdir(dp);

    printf("Inode number : %ld\n", ptr -> d_ino);
    printf("File name : %s\n", ptr -> d_name);   

    return 0;
}

