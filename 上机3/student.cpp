#include <iostream>
#include <cstring>
#include "date.cpp"
using namespace std;

class Student
{
public:
  Student(const char *n = "ssdut", int y = 2023, int m = 8, int d = 28);
  Student(const char *n, Date d);
  void show();
  void setName(const char *n);
  static int getNum();

private:
  int id;
  char name[20];
  Date roll;
  static int number;
};

int Student::number = 0;

Student::Student(const char *n, int y, int m, int d) : roll(y, m, d)
{
  id = ++number;
  if (n == NULL)
    strcpy(name, "ssdut");
  else
    strcpy(name, n);
}

Student::Student(const char *n, Date d) : roll(d)
{
  id = ++number;
  if (n == NULL)
    strcpy(name, "ssdut");
  else
    strcpy(name, n);
}

void Student::show()
{
  cout << "id: " << id << endl;
  cout << "name: " << name << endl;
  cout << "roll: ";
  roll.print();
}

void Student::setName(const char *n)
{
  if (n == NULL)
    strcpy(name, "ssdut");
  else
    strcpy(name, n);
}

int Student::getNum()
{
  return number;
}

int main()
{
  Date d(2022, 9, 1);
  Student s[4] = {Student("S1", 1994, 8, 3), Student("S2", d), Student("S3")};
  for (int i = 0; i < 4; i++)
  {
    s[i].show();
    cout << endl;
  }
  cout << "number: " << Student::getNum() << endl;
  return 0;
}
