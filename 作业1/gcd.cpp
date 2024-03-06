#include <iostream>
#include <cmath>
using namespace std;

//穷举法
int gcd1(int a, int b)
{
  int low = a < b ? a : b;
  for (int i = low; i > 0; i--)
  {
    if (a % i == 0 && b % i == 0)
    {
      return i;
    }
  }
  return 1;
}

//迭代法
int gcd2(int a, int b)
{
  int t;
  while (b != 0)
  {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << "穷举法：" << gcd1(a, b) << endl;
  cout << "迭代法：" << gcd2(a, b) << endl;
  return 0;
}