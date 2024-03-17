#include <iostream>
using namespace std;

class Date
{
public:
  Date(int y = 1970, int m = 1, int d = 1);
  bool set(int y, int m, int d);
  void print();
  int day_of_year() const;
  int diff(const Date &A);

private:
  bool is_valid(int y, int m, int d);
  bool is_leap(int y) const;
  int year;
  int month;
  int day;
};

Date::Date(int y, int m, int d)
{
  if (!set(y, m, d))
  {
    year = 1970;
    month = 1;
    day = 1;
  }
}

bool Date::set(int y, int m, int d)
{
  if (is_valid(y, m, d))
  {
    year = y;
    month = m;
    day = d;
    return true;
  }
  else
  {
    return false;
  }
}

void Date::print()
{
  cout << month << "/" << day << "/" << year << endl;
}

bool Date::is_leap(int y) const
{
  if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Date::day_of_year() const
{
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  days[1] = is_leap(year) ? 29 : 28;

  int sum = 0;
  for (int i = 0; i < month - 1; i++)
  {
    sum += days[i];
  }
  sum += day;
  return sum;
}

int Date::diff(const Date &A)
{
  int sum = 0;
  for (int i = A.year; i < year; i++)
  {
    if (is_leap(i))
    {
      sum += 366;
    }
    else
    {
      sum += 365;
    }
  }
  sum += (day_of_year() - A.day_of_year());
  return sum;
}

bool Date::is_valid(int y, int m, int d)
{
  if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
  {
    return false;
  }
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  days[1] = is_leap(y) ? 29 : 28;
  if (d > days[m - 1])
  {
    return false;
  }
  return true;
}

int main()
{
  Date invalid_date(2020, 2, 30);
  invalid_date.print(); // 输出默认日期
  Date default_date;
  default_date.print(); // 输出默认日期

  Date a(2024, 3, 11);
  a.print(); // 输出 3/11/2024
  a.set(2019, 2, 29);
  a.print();                       // 输出默认日期 (其实这里最好设置不修改日期，当时出题的时候没注意)
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