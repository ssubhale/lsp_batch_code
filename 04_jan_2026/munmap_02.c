#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int fd = 0;
    char *ptr = NULL;

    struct stat sObj;

    fd = open("pune.txt", O_RDWR | O_CREAT, 0777);

    ftruncate(fd, 64);

    fstat(fd, &sObj);

    ptr = mmap(NULL, sObj.st_size, PROT_EXEC | PROT_WRITE, MAP_SHARED, fd, 0);

    strcpy(ptr, "Jay Ganesh...!");

    printf("Data from mmapped memory is : %s\n", ptr);

    munmap(ptr, sObj.st_size);

    return 0;
}

