//实现栈的基本操作，并设计主函数对该类的功能进行测试，
//注意对特殊情况/边界条件的测试。

#include <iostream>
using namespace std;

class Stack
{
public:
  Stack(int n);      // 初始化, 栈的容量为 n
  ~Stack();          // 析构函数
  bool push(char x); // 将 x 入栈存在栈顶位置，返回知否入栈成功（如果栈已满则无法入栈）
  char pop();   // 将栈顶元素出栈，返回栈顶元素，并修改栈顶位置
  bool empty(); // 判断栈是否为空
  bool full();  // 判断栈是否已满
private:
  char *buffer;
  int top;  // 栈顶位置
  int size; // 栈的容量(最多能存放的元素个数)
};

Stack::Stack(int n)
{
  buffer = new char[n];
  top = -1;
  size = n;
}

Stack::~Stack()
{
  delete[] buffer;
}

bool Stack::push(char x)
{
  if (full())
  {
    return false;
  }
  buffer[++top] = x;
  return true;
}

char Stack::pop()
{
  if (empty())
  {
    return '\0';
  }
  return buffer[top--];
}

bool Stack::empty()
{
  return top == -1;
}

bool Stack::full()
{
  return top == size - 1;
}

int main()
{
  Stack s(3);
  s.push('a');
  s.push('b');
  s.push('c');
  s.push('d');
  while (!s.empty())
  {
    std::cout << s.pop() << std::endl;
  }
  return 0;
}