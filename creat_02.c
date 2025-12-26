#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int fd = 0;
  
  fd = creat(argv[1], 0777);
  
  if (fd == -1)
  {
    printf("Enable to create file\n");
  }
  else
  {
    printf("File gets created successfully with fd %d\n", fd);
  }
  
  return 0;
}
