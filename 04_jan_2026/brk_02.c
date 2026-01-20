#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    void *currentBreak = NULL;

    currentBreak = sbrk(0);
    printf("Current process beak %p\n", currentBreak);

    brk((char *)currentBreak + 100);

    strcpy((char *) currentBreak, "Jay Ganesh...!");

    printf("Data from new memory : %s\n", (char *) currentBreak);

    sbrk(-100);      // free

    return 0;
}

