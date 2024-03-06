#include <iostream>
#include <string>

class Time {
    int hour;   // 0-23
    int minute;  // 0-59
    int second;  // 0-59

public:
    // 默认构造函数
    Time() : hour(0), minute(0), second(0) {}

    // 输入合法时间
    void setTime() {
        std::cout << "请输入小时 (0-23): ";
        std::cin >> hour;
        std::cout << "请输入分钟 (0-59): ";
        std::cin >> minute;
        std::cout << "请输入秒 (0-59): ";
        std::cin >> second;
    }

    // 设置合法时间
    void setTime(int h, int m, int s) {
        hour = (h >= 0 && h < 24) ? h : 0;
        minute = (m >= 0 && m < 60) ? m : 0;
        second = (s >= 0 && s < 60) ? s : 0;
    }

    // 输出时间
    void showTime() const {
        std::cout << std::string(hour < 10 ? "0" : "") << hour << ":"
                  << std::string(minute < 10 ? "0" : "") << minute << ":"
                  << std::string(second < 10 ? "0" : "") << second << std::endl;
    }

    // 比较时间，并输出靠后的时间
    int judge(const Time& t) const {
        if (hour > t.hour || (hour == t.hour && minute > t.minute) ||
            (hour == t.hour && minute == t.minute && second >= t.second)) {
            return 1; // 当前时间靠后
        } else if (hour < t.hour || (hour == t.hour && minute < t.minute) ||
                   (hour == t.hour && minute == t.minute && second < t.second)) {
            return -1; // 参数时间靠后
        } else {
            return 0; // 时间相同
        }
    }
};

int main() {
    Time t1, t2;

    // 设置时间
    std::cout << "设置时间 t1: ";
    t1.setTime();
    std::cout << "设置时间 t2: ";
    t2.setTime(12, 30, 45);

    // 显示时间
    std::cout << "时间 t1: ";
    t1.showTime();
    std::cout << "时间 t2: ";
    t2.showTime();

    // 比较时间
    int result = t1.judge(t2);
    if (result == 1) {
        std::cout << "t1 是靠后的时间。" << std::endl;
    } else if (result == -1) {
        std::cout << "t2 是靠后的时间。" << std::endl;
    } else {
        std::cout << "t1 和 t2 时间相同。" << std::endl;
    }

    return 0;
}