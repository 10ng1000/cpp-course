#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    int sum = 0;
    int start = 0;
    int end = 0;
    int temp = 0;
    //保持start到end之间是目前为止最大的子数组
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
            start = temp;
            end = i;
        }
        //sum小于零表示，如果考虑的子数组加上了前面的数组，反而会变小，所以把start移到下一个位置
        if (sum < 0)
        {
            sum = 0;
            temp = i + 1;
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;
    return 0;
}