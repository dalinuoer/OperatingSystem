#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int pid, i;
  if ((pid = fork()) < 0)
  {
    printf("child process was created failed!\n");
    return;
  }
  else if (pid == 0)
  {
    lockf(1, 1, 0);
    for (i = 0; i < 5; i++)
      printf("This is child(pid = %d) process:b\n", getpid());
    lockf(1, 0, 0);
  }
  else
  {
    lockf(1, 1, 0);
    for (i = 0; i < 5; i++)
      printf("Parent process:a\n");
    lockf(1, 0, 0);
  }
}
