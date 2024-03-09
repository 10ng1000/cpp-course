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
