#include <stdio.h>
#include <sys/stat.h>


int main(void)
{
    int iRet = 0;

    iRet = mkdir("./data_applications", 0777);

    if (iRet == 0)
    {
        printf("Directory gets created\n");
    }
    
    return 0;
}

