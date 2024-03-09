class Time
{
private:
    int hour = 0;
    int minute = 0;
    int second = 0;

public:
    void Set(int hour = 0, int minute = 0, int second = 0); // 默认参数设置时间
    void Set(int, int);                                     // 重载函数设置时间，和默认参数二选一即可
    void Set(int);                                          // 重载函数设置时间，和默认参数二选一即可
    void Tick();                                            // +1s
    void Show();                                            // 输出时间，采用24小时制，参考H:M:S
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
    time.Show(); // 输出0:0:0
    return 0;
}
