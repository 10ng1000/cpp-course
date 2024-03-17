#include <iostream>
using namespace std;

class Time
{
private:
    int hour = 0;
    int minute = 0;
    int second = 0;

public:
    void Set(int hour = 0, int minute = 0, int second = 0){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    } // 默认参数设置时间
    void Set(int hour, int minute){
        this->hour = hour;
        this->minute = minute;
    }                                     // 重载函数设置时间，和默认参数二选一即可
    void Set(int hour){
        this->hour = hour;
    }                                          // 重载函数设置时间，和默认参数二选一即可
    void Tick() {
        second++;
        if (second == 60) {
            second = 0;
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
                if (hour == 24) {
                    hour = 0;
                }
            }
        }
    }                                            // +1s
    void Show(){
        cout << hour << ":" << minute << ":" << second << endl;
    }                                            // 输出时间，采用24小时制，参考H:M:S
};

int main()
{
    Time time;
    time.Set(13, 1, 59); // 采用24小时制
    time.Show();         // 输出13:1:59
    time.Tick();
    time.Show(); // 输出13:2:0
    time.Set(13, 59, 59);
    time.Tick();
    time.Show(); // 输出14:0:0
    time.Set(23, 59, 59);
    time.Tick();
    time.Show(); // 输出0:0:0
    return 0;
}
