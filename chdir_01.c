#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    char path[50];

    memset(path, '\0', sizeof(path));

    getcwd(path, sizeof(path));

    printf("Current directory name : %s\n", path);

    chdir("./data_applications");

    getcwd(path, sizeof(path));
    
    printf("Current directory name : %s\n", path);
    
    return 0;
}

