#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    void *currentBreak = NULL;
    void *newBreak = NULL;

    currentBreak = sbrk(0);
    printf("Current process beak %p\n", currentBreak);

    newBreak = sbrk(100);

    strcpy((char *) newBreak, "Jay Ganesh...!");

    printf("Data from new memory : %s\n", (char *) newBreak);

    sbrk(-100);      // free

    return 0;
}

