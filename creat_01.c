#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int fd = 0;
  
  fd = creat("lsp.txt", 0777);
  
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
