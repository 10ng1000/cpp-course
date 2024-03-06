/*
1.见代码
2.swap3
3.Jackson, Gates
  Gackson, Jates
4.swap4
5.见swap函数，能构成重载
*/

#include <stdio.h>
#include <string.h>

void swap1(char a, char b)
{
  char t;
  t = a;
  a = b;
  b = t;
}

void swap2(char *p, char *q)
{
  char *t = 0;
  t = p;
  p = q;
  q = t;
}

void swap3(char *p, char *q)
{
  char t;
  t = *p;
  *p = *q;
  *q = t;
}

void swap4(char **p, char **q)
{
  char *t = 0;

  t = *p;
  *p = *q;
  *q = t;
}

void swap(char &p, char &q)
{
  char t;
  t = p;
  p = q;
  q = t;
}

void swap(char *&p, char *&q)
{
  char *t = 0;
  t = p;
  p = q;
  q = t;
}


int main()
{
  char c1 = 'A', c2 = 'B';
  char str1[] = "Jackson", str2[] = "Gates";
  char *p1 = str1, *p2 = str2;
  swap2(p1, p2);
  printf("%s, %s\n", p1, p2); // ① 
  swap3(p1, p2);
  printf("%s, %s\n", p1, p2); // ②

  swap3(&c1, &c2);
  printf("%c, %c\n", c1, c2); // 该句应该输出B，A

  p1 = "Gates";
  p2 = "Jackson";

  swap4(&p1, &p2);
  printf("%s, %s\n", p1, p2); // 该句应该输出Jackson，Gates

  swap(c1, c2);
  printf("%c, %c\n", c1, c2); // 交换为原来的值
  swap(p1, p2);
  printf("%s, %s\n", p1, p2); // 交换为原来的值
  return 0;
}