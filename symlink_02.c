#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(void)
{
    int iRet = 0;

    iRet = symlink("./lsp.txt", "./test_applications/lspl.txt");

    if (iRet == 0)
    {
        printf("Symlink is successfull\n");
    }
    else
    {
        printf("Symlink nnot created\n");
    }

    printf("Error : %s\n", strerror(errno));
    
    return 0;
}

