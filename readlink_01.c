#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int fd = 0;

    fd = open("./test_applications/lspl.txt", O_RDONLY);        // Issue

    if (fd == -1)
    {
        printf("Unable to open file %s\n", strerror(errno));
        return -1;
    }

    printf("File with open fd : %d \n", fd);

    close(fd);

    return 0;
}

