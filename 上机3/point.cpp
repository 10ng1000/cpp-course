/*定义并实现一个 Point 类，一个“PointSet”类（点的集合）。 PointSet 类可以
将不超过 5 个点放入集合中或将它们从集合中取出， 也可以对所有点成员进行统一处
理（将所有点同时设置）。 集合超过 5 个元素后，不能再添加元素。 按照如下设计完
成类实现*/

#include <iostream>
using namespace std;

class Point
{
public:
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void set(double x, double y)
  {
    this->x = x;
    this->y = y;
  }
  double getX() const { return x; }
  double getY() const { return y; }

private:
  double x, y;
};

class PointSet
{
private:
  int num;        // 点的实际数量
  Point point[5]; // Array of points
public:
  PointSet(int n = 0); // 初始没有点
  bool add(Point &p);  // 加入一个点.
  // 如果超过 5 个点则加入失败.
  Point get(int n); // 获得第 n 号点, 点的排序从 0 号开始
  // 检查 n 的合理性. 如果该点不存在，则显示提示信息.
  void setAll(double x, double y);            // 将所有的点设置为同一个坐标 x, y
  int getNum();                               // 返回集合中点的个数
  bool resetPoint(int n, double x, double y); // 将第 n 号点的坐标设置x，y
  // 如果该点不存在 return false
  void show(); // 输出所有的点
};

PointSet::PointSet(int n)
{
  num = n;
}

bool PointSet::add(Point &p)
{
  if (num >= 5)
  {
    return false;
  }
  point[num++] = p;
  return true;
}

Point PointSet::get(int n)
{
  if (n < 0 || n >= num)
  {
    cout << "点不存在" << endl;
    return Point();
  }
  return point[n];
}

void PointSet::setAll(double x, double y)
{
  for (int i = 0; i < num; i++)
  {
    point[i].set(x, y);
  }
}

int PointSet::getNum()
{
  return num;
}

bool PointSet::resetPoint(int n, double x, double y)
{
  if (n < 0 || n >= num)
  {
    return false;
  }
  point[n].set(x, y);
  return true;
}

void PointSet::show()
{
  for (int i = 0; i < num; i++)
  {
    cout << "Point " << i << " : (" << point[i].getX() << ", " << point[i].getY() << ")" << endl;
  }
}

int main()
{
  PointSet ps;
  Point p1(1, 2), p2(3, 4), p3(5, 6), p4(7, 8), p5(9, 10), p6(11, 12);
  ps.add(p1);
  ps.add(p2);
  ps.add(p3);
  ps.add(p4);
  ps.add(p5);
  ps.add(p6);
  ps.show();
  ps.setAll(0, 0);
  ps.show();
  ps.resetPoint(0, 1, 1);
  ps.show();
  return 0;
}



