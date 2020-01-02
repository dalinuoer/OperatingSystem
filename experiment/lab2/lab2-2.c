#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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
    printf("I am son!pid = %d\n", getpid());
    exit(5);
  }
  
  pid_t pid;
  int status, i;

  if ((pid2 = fork()) < 0)
  {
    printf("Process was created failed!\n");
    return;
  }  
  else if (pid2 == 0)
  {
    lockf(1, 1, 0);
    printf("I am daughter!pid = %d\n", getpid());
    lockf(1, 0, 0);
    return;
  }
  else
  {
    sleep(1);
    printf("I am father!\n");
    pid = wait(&status);
    i = WEXITSTATUS(status);
    printf("child process's pid = %d, exit status = %d\n", pid, i);
    return;
  }
}
