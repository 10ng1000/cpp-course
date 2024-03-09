#include <iostream>
using namespace std;

class Date
{
public:
  Date(int y, int m, int d);
  bool set(int y, int m, int d);
  void print();
  int day_of_year();
  int diff(const Date &A);

private:
  bool is_valid(int y, int m, int d);
  int year;
  int month;
  int day;
};

int main()
{
  Date invalid_date(2020, 2, 30);
  invalid_date.print(); // 输出默认日期
  Date default_date;
  default_date.print(); // 输出默认日期

  Date a(2024, 3, 11);
  a.print(); // 输出 3/11/2024
  a.set(2019, 2, 29);
  a.print();                       // 输出默认日期
  a.set(2024, 2, 29);
  a.print();                       // 输出 2/29/2024
  a.set(2024, 3, 11);
  cout << a.day_of_year() << endl; // 输出 71

  Date b(2024, 5, 1);
  cout << a.diff(b) << endl; // 输出 -51
  b.set(2023, 12, 25);
  cout << a.diff(b) << endl; // 输出 77
  cout << a.diff(a) << endl; // 输出 0
}