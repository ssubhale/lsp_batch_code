#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    int fd = 0, iRet = 0;
    off_t offset = 0;
    char buffer[50] = "Pune";
    
    fd = open("lsp.txt", O_WRONLY | O_APPEND);

    iRet = pwrite(fd, buffer, 4, 10);

    offset = lseek(fd, 0, SEEK_CUR);

    printf("Current offset is %ld\n", offset);

    return 0;
}

