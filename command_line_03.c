#include <stdio.h>

int main(int argc, char *argv[])
{
  int iCounter = 0;
  
  printf("No. of command line args are %d\n", argc);
  
  for (iCounter; iCounter < argc; iCounter++)
  {
    printf("%s\n", argv[iCounter]);
  }
  
  return 0;
}
