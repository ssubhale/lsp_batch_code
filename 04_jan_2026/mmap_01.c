#include <stdio.h>
#include <string.h>
#include <sys/mman.h>


int main(void)
{
    char *ptr = NULL;

    ptr = mmap(NULL, 1024, PROT_EXEC | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    strcpy(ptr, "Jay Ganesh...!");

    printf("Data from mmapped memory is : %s\n", ptr);

    return 0;
}

