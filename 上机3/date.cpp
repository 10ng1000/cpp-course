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