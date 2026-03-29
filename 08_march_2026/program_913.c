#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void ShowProcessInformation(int);

void ShowMemoryInformation(int);

void GetSectionType(char *, char *, char *);


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

    ShowMemoryInformation(iPID);

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


void ShowMemoryInformation(int iPID)
{
    FILE *fp = NULL;
    char chLine[80];
    char fileName[100];

    sprintf(fileName, "/proc/%d/maps", iPID);

    printf("Accessing file : %s\n", fileName);

    fp = fopen(fileName, "r");

    if (NULL == fp)
    {
        printf("Unable to access system file : %s\n", fileName);
        return;
    }

    printf("\n");
    printf("----------------------------------------------------------------------------------------- \n");
    printf("----------------------------------- Memory Information ---------------------------------- \n");
    printf("----------------------------------------------------------------------------------------- \n");

    printf("----- header ----- \n");

    while (fgets(chLine, sizeof(chLine), fp) != NULL)
    {
        // Remove this varibale from while loop

        char chAddress[100], chParams[10], chOffst[20], chDev[20], chDetails[300];

        unsigned long iNode;
        unsigned long iStart;
        unsigned long iEnd;
        unsigned long iSizeKB;
        char chSection[50];
        int iRet = 0;

        iRet = sscanf(chLine, "%s %s %s %s %lu %[^\n]", chAddress, chParams, chOffst, chDev, &iNode, chDetails);

        if (iRet >= 5)
        {
            sscanf(chAddress, "%lx - %lx", &iStart, &iEnd);
            iSizeKB = (iEnd - iStart);

            GetSectionType(chDetails, chParams, chSection);

            if (strlen(chDetails) == 0)
            {
                strcpy(chDetails, "Anonymous");
            }

            printf("%lx-%lx %lu %s %s %s\n", iStart, iEnd, iSizeKB, chParams, chSection, chDetails);
        }

    }

    printf("---------------------------------------------------------------------------------------- \n");

    fclose(fp);

    return;
}



void GetSectionType(char * chDetails, char *chParams, char * chSection)
{
    if (strcmp(chDetails, "[heap]") == 0)
    {
        strcpy(chSection, "HEAP");
    }

    else if (strcmp(chDetails, "[stack]") == 0)
    {
        strcpy(chSection, "STACK");
    }

    else if (strcpy(chDetails, "[vdso]") == 0)
    {
        strcpy(chSection, "VDSO");
    }

    else if (strcmp(chDetails, "[vvar]") == 0)
    {
        strcpy(chSection, "VVAR");
    }

    // else if (strcmp(chParams[2], "x") == 0)
    // {
    //     strcpy(chSection, "TEXT");
    // }

    // else if (strcmp)
}


/*
        TEXT / Code         Binary Instructions
        Data                Global Variables
        Stack               Local Variables
        VDSO                Virtual Dynamic Shared Object
        VVAR                Virtual Variables
        VSYSCALL            Virtual System Call Page
        Other               Other memory regions

        Create this project as menu driven program
         
*/

