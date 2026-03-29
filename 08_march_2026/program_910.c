#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
    FILE * fp = NULL;
    char chBuffer[256];

    fp = fopen("/proc/meminfo", "r");

    if (NULL == fp)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    printf("------------------------------------------------------------------------------------ \n");
    printf("----------------------------- Marvelloue Memory Scanner ---------------------------- \n");
    printf("------------------------------------------------------------------------------------ \n");

    while (fgets(chBuffer, sizeof(chBuffer), fp) != NULL)
    {
        printf("%s\n", chBuffer);
    }

    printf("------------------------------------------------------------------------------------ \n");

    fclose(fp);
    
    return 0;
}

