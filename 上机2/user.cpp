class User
{
private:
    unsigned int id = 0; // id 非负
    char password[6];    // 6为密码，默认000000

public:
    User(unsigned int id);                                  // 根据id构造User对象
    void PrinId();                                          // 输出id
    void SetPassword(char *oldPassword, char *newPassword); // 设置密码，比较新旧密码，提示操作是否成功
};

int main()
{
    User user(123456);
    user.PrinId();                         // 输出123456
    user.SetPassword("000000", "11111A");  // 输出密码设置失败
    user.SetPassword("000000", "1111111"); // 输出密码设置失败
    user.SetPassword("0", "111111");       // 输出密码设置失败
    user.SetPassword("100000", "111111");  // 输出密码设置失败
    user.SetPassword("000000", "111111");  // 输出密码设置成功
    return 0;
}