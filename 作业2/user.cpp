#include <iostream>
#include <cstring>
using namespace std;

class User
{
private:
    unsigned int id = 0; // id 非负
    char password[7];    // 6为密码，默认000000，必须为数字

public:
    User(unsigned int id) {
        this->id = id;
        for (int i = 0; i < 6; i++) {
            password[i] = '0';
        }
    }                                  // 根据id构造User对象
    void PrinId() {
        cout << id << endl;
    }                                          // 输出id
    void SetPassword(char *oldPassword, char *newPassword) {
        // newPassword的长度
        if (strlen(newPassword) != 6) {
            cout << "密码设置失败" << endl;
            return;
        }
        int i = 0;
        // 新密码必须是6位数字
        while (i < 6 && password[i] == oldPassword[i] && newPassword[i] >= '0' && newPassword[i] <= '9') {
            i++;
        }
        if (i == 6) {
            for (i = 0; i < 6; i++) {
                password[i] = newPassword[i];
            }
            cout << "密码设置成功" << endl;
        } else {
            cout << "密码设置失败" << endl;
        }
    } // 设置密码，比较新旧密码，提示操作是否成功

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