#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int iRet = 0;

    iRet = rmdir("./data_applications");

    if (iRet == 0)
    {
        printf("Directory gets deleted\n");
    }

    printf("Error : %s\n", strerror(errno));
    
    return 0;
}

