#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int iRet = 0;

    iRet = rename("demox.txt", "demo.txt");

    if (iRet == 0)
    {
        printf("File renamed successfully\n");
    }
    else
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    return 0;
}
