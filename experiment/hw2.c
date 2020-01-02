/*
* 借助栈实现LRU算法
*/
#include <stdio.h>

// 若n在数组中，返回其位置；否则，返回-1
int inStack(int stack[5], int stackLen, int n)
{
  int position = -1;
  int i;// counter
  for (i = 0; i < stackLen; ++i)
  {
    if (stack[i] == n)
    {
      position = i;
      break;
    }
  }
  return position;
}

// 将数组中stack[n]以后的数向前移动一个
void move(int stack[5], int stackLen, int n)
{
  int i;// counter
  for (i = n; i < stackLen - 1; ++i)
  {
    stack[i] = stack[i + 1];
  }
}

int main()
{
  int visit[] = {4, 7, 0, 7, 1, 0, 1, 2, 1, 2, 6};// 页号访问顺序
  int visitLen = sizeof(visit) / sizeof(int);
  int stack[5] = {-1};// 栈
  int count = 0;// 栈中页面号的个数
  int i, j;// counter

  for (i = 0; i < visitLen; ++i)
  {
    int position = inStack(stack, count, visit[i]);
    if (count == 5)// 栈已满
    {
      if (position == -1)// 新页面不在栈中
      {
        // stack[0]被置换出去
        printf("%d out!\n", stack[0]);
        move(stack, count, 0);// 将stack[0]~stack[3]向前移一个
        stack[4] = visit[i];
      }
      else// 新页面在栈中
      {
        move(stack, count, position);
        stack[4] = visit[i];
      }
    }
    else// 栈未满
    {
      if (position == -1)// 页面不在栈中
      {
        stack[count] = visit[i];
        ++count;
      }
      else// 页面在栈中
      {
        move(stack, count, position);
        stack[count - 1] = visit[i];
      }
    }
  }
  // 打印栈，从栈顶到栈底
  for (i = 4; i >= 0; --i)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
  return 0;
}
