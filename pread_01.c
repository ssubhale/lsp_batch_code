#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    int fd = 0;
    off_t offset = 0;
    char buffer[50];
    
    memset(buffer, '\0', sizeof(buffer));

    fd = open("lsp.txt", O_RDONLY);

    offset = lseek(fd, 0, SEEK_SET);

    printf("Current offset is %ld\n", offset);

    read(fd, buffer, 10);

    offset = lseek(fd, 0, SEEK_CUR);

    printf("Current offset is %ld\n", offset);

    return 0;
}

