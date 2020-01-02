#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int pid1, pid2;

  if ((pid1 = fork()) < 0)
  {
    printf("Process was created failed!\n");
    return;
  }
  else if (pid1 == 0)
  {
    printf("I am son!\n");
    return;
  }

  if ((pid2 = fork()) < 0)
  {
    printf("Process was created failed!\n");
    return;
  }  
  else if (pid2 == 0)
  {
    printf("I am daughter!\n");
    return;
  }
  else
  {
    printf("I am father!\n");
    return;
  }
}
