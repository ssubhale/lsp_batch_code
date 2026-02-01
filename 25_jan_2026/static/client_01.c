#include <stdio.h>
#include <stdlib.h>


int Addition(int, int);
int Subtraction(int, int);


int main(void)
{
    int iResult = 0;

    iResult = Addition(12,10);

    printf("Addition is : %d\n", iResult);

    iResult = Subtraction(12,10);

    printf("Subtraction is : %d\n", iResult);

    return 0;
}

