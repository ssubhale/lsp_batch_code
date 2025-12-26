#include <stdio.h>
#include <unistd.h>


int main(void)
{
    int iRet = 0;

    iRet = truncate("demo.txt", 30);

    if (iRet == 0)
    {
        printf("Truncate is successfull\n");
    }
    else
    {
        printf("There is issue in truncate call\n");
    }


    return 0;
}
