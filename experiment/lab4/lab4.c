#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
  int filedes[2];
  pipe(filedes);

  int pid;
  
  if ((pid = fork()) < 0)
  {
    printf("Process was created failed!\n");
    return;
  }
  else if (pid == 0)
  {
    printf("in the child process...\n");
    char *str = "is sending a message to parent!";
    close(filedes[0]);// 关闭读端
    write(filedes[1], str, strlen(str));// 写数据
    return;
  }
  else
  {
    printf("in the parent process...\n");
    char buf[50];
    close(filedes[1]);// 关闭写端
    read(filedes[0], buf, sizeof(buf));// 读数据
    printf("%d bytes of data was received from child:\n%s\n", strlen(buf), buf);
    return;
  }
}
