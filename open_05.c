#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int fd = 0;
  
  fd = open("second.c", O_CREAT | O_TRUNC, 0777);
  
  if (fd == -1)
  {
    printf("Enable to create file\n");
  }
  else
  {
    printf("File gets successfully created with fd : %d\n", fd);
  }
  
  close(fd);
  
  return 0;
}
