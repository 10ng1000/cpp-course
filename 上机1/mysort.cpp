#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void mySort(int &a, int &b, int &c)
{
  //确保a是最小的
  if (a > b)
    swap(a, b);
  if (a > c)
    swap(a, c);
  //确保b是次小的
  if (b > c)
    swap(b, c);
}

void mySort(int *a, int *b, int *c)
{
  //确保a是最小的
  if (*a > *b)
    swap(*a, *b);
  if (*a > *c)
    swap(*a, *c);
  //确保b是次小的
  if (*b > *c)
    swap(*b, *c);
}

void mySort(int arr[], int len)
{
  //冒泡排序
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

void input(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }
}

void output(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main()
{
  int a, b, c;
  cout << "-----------input 3 datas for test1------" << endl;
  cin >> a >> b >> c;                        // 例如输入 20 8 15
  mySort(a, b, c);                           // 升序排列
  cout << a << ' ' << b << ' ' << c << endl; //  输出8 15 20
  cout << "-----------input 3 datas for test2------" << endl;
  cin >> a >> b >> c;                        // 例如输入 30, 80, -40
  mySort(&a, &b, &c);                        // 重载函数 升序排列
  cout << a << ' ' << b << ' ' << c << endl; //-40 30 80

  const int n = 6;
  int arr[n];
  cout << "-----------input" << n << " datas for test3------" << endl;
  input(arr, n);  // 输入n个整数
  mySort(arr, 3); // 数组前3个数据升序排列
  output(arr, n); // 遍历输出数组
  return 0;
}
