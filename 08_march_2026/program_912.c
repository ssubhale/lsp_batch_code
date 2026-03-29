#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void ShowProcessInformation(int);

int main(void)
{
    int iPID  = 0;

    printf("---------------------------------------------------------------------------------------- \n");
    printf("----------------------------- Marvelloue Process Inspector ----------------------------- \n");
    printf("---------------------------------------------------------------------------------------- \n");

    printf("Enter the PID of a process that you want to inspect : ");
    scanf("%d", &iPID);

    if (iPID <= 0)
    {
        printf("Invalid PID\n");
        return -1;
    }

    ShowProcessInformation(iPID);

    return 0;
}

void ShowProcessInformation(int iPID)
{
    FILE *fp = NULL;
    char chLine[80];
    char fileName[100];

    sprintf(fileName, "/proc/%d/status", iPID);

    printf("Accessing file : %s\n", fileName);

    fp = fopen(fileName, "r");

    if (NULL == fp)
    {
        printf("Unable to access system file : %s\n", fileName);
        return;
    }

    printf("\n");
    printf("----------------------------------------------------------------------------------------- \n");
    printf("---------------------------------- Process Information ---------------------------------- \n");
    printf("----------------------------------------------------------------------------------------- \n");

    while (fgets(chLine, sizeof(chLine), fp) != NULL)
    {
        if (
            strncmp(chLine, "Name:", 5) == 0 ||
            strncmp(chLine, "State:", 6) == 0 ||
            strncmp(chLine, "Pid:", 4) == 0 ||
            strncmp(chLine, "Threads:", 8) == 0
        )
        {
            printf("%s\n", chLine);
        }
    }

    printf("----------------------------------------------------------------------------------------- \n");

    return;
}

