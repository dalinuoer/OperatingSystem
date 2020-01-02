#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int pid;
  if ((pid = fork()) < 0)
  {
    printf("son was created failed!\n");
    return;
  }
  else if (pid == 0)
  {
    printf("I am son!\n");
    return;
  }
  else
  {
    printf("I am father!\n");
    return;
  }
}
