#include <iostream>
using namespace std;

int main()
{
  int count = 0;
  for (int i = 0; i <= 100; i++)
  {
    for (int j = 0; j <= 50; j++)
    {
      for (int k = 0; k <= 20; k++)
      {
        if (i + 2 * j + 5 * k == 100)
        {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}