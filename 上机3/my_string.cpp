#include <cstdio>
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class myString
{
public:
  myString(const char *pn = NULL);
  myString(const myString &);
  ~myString();
  void set(const char *pn);
  void print();
  int getLen();
  void toUpper(); // 转化为大写字符串 void toLower( ); //转化为小写字符串
  void toLower(); // 转化为小写字符串

private:
  char *pStr;
  int size;
  // 指向存储字符串的空间 //包含字符的数目
};

myString::myString(const char *pn)
{
  if (pn == NULL)
  {
    pStr = NULL;
    size = 0;
    return;
  }
  size = strlen(pn);
  pStr = new char[size + 1];
  strcpy(pStr, pn);
}

myString::myString(const myString &str)
{
  if (str.pStr == NULL)
  {
    pStr = NULL;
    size = 0;
    return;
  }
  size = str.size;
  pStr = new char[size + 1];
  strcpy(pStr, str.pStr);
}

myString::~myString()
{
  if (pStr != NULL)
  {
    delete[] pStr;
  }
}

void myString::set(const char *pn)
{
  if (pStr)
    delete[] pStr;
  if (pn == NULL)
  {
    pStr = NULL;
    size = 0;
    return;
  }
  size = strlen(pn);
  pStr = new char[size + 1];
  strcpy(pStr, pn);
}

void myString::print()
{
  if (pStr == NULL)
  {
    std::cout << "空字符串" << std::endl;
    return;
  }
  for (int i = 0; i < size; i++)
  {
    std::cout << pStr[i];
  }
  std::cout << std::endl;
}

int myString::getLen()
{
  return size;
}

void myString::toUpper()
{
  for (int i = 0; i < size; i++)
  {
    if (pStr[i] >= 'a' && pStr[i] <= 'z')
    {
      pStr[i] -= 32;
    }
  }
}

void myString::toLower()
{
  for (int i = 0; i < size; i++)
  {
    if (pStr[i] >= 'A' && pStr[i] <= 'Z')
    {
      pStr[i] += 32;
    }
  }
}

int main()
{
  myString s0, s1("hello");
  s0.print(); // 输出“空字符串”
  s0.set("world");
  s0.print(); // 输出“world”
  s1.toUpper();
  std::cout << s1.getLen() << endl; // 输出 5
  myString s2 = s1;
  s2.print(); // 输出“HELLO”
  s2.toLower();
  s1.print(); // 输出“HELLO”
  return 0;
}