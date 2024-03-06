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
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
            start = temp;
            end = i;
        }
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