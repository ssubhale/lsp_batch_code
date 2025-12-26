#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int fd = 0;
  
  fd = open("first.c", O_RDWR);
  
  if (fd == -1)
  {
    printf("Enable to open file\n");
  }
  else
  {
    printf("File gets successfully opened with fd : %d\n", fd);
  }
  
  return 0;
}
