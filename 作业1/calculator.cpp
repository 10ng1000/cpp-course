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