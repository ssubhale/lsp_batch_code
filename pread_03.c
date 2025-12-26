#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    int fd = 0, iRet = 0;
    off_t offset = 0;
    char buffer[50];
    
    memset(buffer, '\0', sizeof(buffer));

    fd = open("lsp.txt", O_RDONLY);

    // offset = lseek(fd, 10, SEEK_SET);
    // printf("Current offset is %ld\n", offset);

    iRet = pread(fd, buffer, 5, 10);

    printf("\n");

    write(1, buffer, iRet);
    
    printf("\n");

    offset = lseek(fd, 0, SEEK_CUR);

    printf("Current offset is %ld\n", offset);

    return 0;
}

