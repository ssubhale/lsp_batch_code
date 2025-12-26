#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(void)
{
    int iRet = 0;

    iRet = symlink("demox.txt", "hello.txt");

    if (iRet == 0)
    {
        printf("Symlink is successfull\n");
    }
    else
    {
        printf("Symlink nnot created\n");
    }

    printf("Error : %s", strerror(errno));
    
    return 0;
}

