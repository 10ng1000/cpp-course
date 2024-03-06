//简易计算器，从键盘输入两个整数和一个字符（+、-、*、/），分别对两个数进行加、减、乘和除的运算。如输入：23 123 +；输出计算结果：23+123=146。要求利用IO流运算符进行输入和输出。
#include <iostream>
using namespace std;

int main(){
  int a, b;
  char c;
  cin >> a >> b >> c;
  switch (c){
    case '+':
      cout << a << "+" << b << "=" << a + b << endl;
      break;
    case '-':
      cout << a << "-" << b << "=" << a - b << endl;
      break;
    case '*':
      cout << a << "*" << b << "=" << a * b << endl;
      break;
    case '/':
      if (b == 0){
        cout << "除数不能为0" << endl;
        break;
      }
      cout << a << "/" << b << "=" << (float)a / b << endl;
      break;
    default:
      cout << "error" << endl;
  }
  return 0;
}