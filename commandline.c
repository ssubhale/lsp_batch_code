#include <stdio.h>

int main(int argc, char *argv[])
{

  int iCounter = 0;

  printf("Inside command line process\n");

  printf("Command line arguments are \n");

  for (iCounter; iCounter < argc; iCounter++)
  {
    printf("%s\n", argv[iCounter]);
  }
  
  return 0;
}

