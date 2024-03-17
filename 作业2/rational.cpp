#include <iostream>
using namespace std;

class Rational
{
public:
  Rational(int nn = 1, int mm = 1); // 构造函数
  Rational add(const Rational &A);  // 加
  Rational sub(const Rational &A);  // 减
  Rational mul(const Rational &A);  // 乘
  Rational div(const Rational &A);  // 除
  void print();                     // 以分数形式显示，注意约分
private:
  void simple(); // 约分
  int m;         // 分母
  int n;         // 分子
};

Rational::Rational(int nn, int mm)
{
  if (mm == 0)
  {
    cout << "分母不能为0" << endl;
    return;
  }
  n = nn;
  m = mm;
  simple();
}

Rational Rational::add(const Rational &A)
{
  int nn = n * A.m + m * A.n;
  int mm = m * A.m;
  Rational result(nn, mm);
  return result;
}

Rational Rational::sub(const Rational &A)
{
  int nn = n * A.m - m * A.n;
  int mm = m * A.m;
  Rational result(nn, mm);
  return result;
}

Rational Rational::mul(const Rational &A)
{
  int nn = n * A.n;
  int mm = m * A.m;
  Rational result(nn, mm);
  return result;
}

Rational Rational::div(const Rational &A)
{
  if (A.n == 0)
  {
    cout << "不能除以0" << endl;
    return Rational(0x3f3f3f3f, 1);
  }
  int nn = n * A.m;
  int mm = m * A.n;
  Rational result(nn, mm);
  return result;
}

void Rational::print()
{
  if (n == 0)
  {
    cout << 0 << endl;
    return;
  }
  if(m == 1)
  {
    cout << n << endl;
    return;
  }
  if (m < 0)
  {
    n = -n;
    m = -m;
  }
  cout << n << "/" << m << endl;
}

void Rational::simple()
{
  int a = n, b = m, c;
  while (b != 0)
  {
    c = a % b;
    a = b;
    b = c;
  }
  n /= a;
  m /= a;
}

int main()
{
  Rational a(1, 2), b(2, 3);
  Rational result = a.add(b);
  result.print(); // 7/6
  result = a.sub(b);
  result.print(); // -1/6
  result = a.mul(b);
  result.print(); // 1/3
  result = a.div(b);
  result.print(); // 3/4

  Rational c(0, 1);
  result = a.mul(c); // 乘0
  result.print();
  result = a.div(c);        // 不能除以0
  Rational test_zero(1, 0); // 分母不能为0
  return 0;
}
