#include <bits/stdc++.h>
using namespace std;

int main() {
  //仿真计算生日不重复的概率
  int n; // n个人
  int M = 1000000; // 仿真次数
  int days [365] = {0};
  int count = 0;
  srand(time(0));
  cin >> n;
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < 365; j++) days[j] = 0;
    for (int j = 0; j < n; j++)
    {
      int day = rand() % 365;
      if (days[day] == 1)
      {
        count++;
        break;
      }
      days[day] = 1;
    }
  }
  //解析计算不重复的概率
  double p = 1;
  for (int i = 0; i < n; i++)
  {
    p *= (365 - i) / 365.0;
  }
  cout << p << endl;
  cout << 1 - (double)count / M << endl;
}