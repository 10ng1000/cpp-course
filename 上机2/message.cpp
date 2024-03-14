//题目：短消息系统，满分30分，输出界面要与截图一致。
/*按要求完成短信类的实现，使得main函数能够正常运行，main函数不得修改
1.开发环境visual studio2022;也可用其他环境
2.类成员函数一般不做输入输出，本例为简单，不做限制
3.send()函数一般返回发送的字符串到短消息网关，本例在函数中直接输出
4.本例重点1要搞清楚字符串成员的两种存储方式
5.本例重点2要搞清楚构造函数和拷贝构造函数
*/

#pragma warning(disable:4996)
#include<iostream>
#include <cstring>
using namespace std;


class Message {        //短消息类
private:
	char* body;      //消息正文
	char from[20];   //发送者
	char to[20];     //接受者
public:
	//参数为消息正文、发送时间、发送者、接受者;若参数b为空指针，body为空指针；若参数f、t为空指针，from、to为空串（即字符数组开头字符为\0）；
	Message(const char* b = NULL, const char* f = NULL, const char* t = NULL);
	Message(const Message& m);
	~Message();
	//发送短消息，消息正文(不空指针并且不空串)、发送者（不空串）、接受者（不空串）都不空时发送成功返回1，失败返回0
	int send(); //这个函数里面允许大家把发送内容直接写输出 ,提示：可调用time的print()。    
	//更新时间，选做，不做者注释掉此函数
};
//完成Message各个成员函数实现 
//参数为消息正文、发送时间、发送者、接受者
Message::Message(const char* b, const char* f, const char* t) {
	if (b) {
		body = new char[strlen(b) + 1];
		strcpy(body, b);
	}
	else
		body = 0;
	if (f)
		strcpy(from, f);
	else
		from[0] = '\0';
	if (t)
		strcpy(to, t);
	else
		to[0] = '\0';
}
Message::Message(const Message& m) {
	if (m.body) {//不是空指针
		body = new char[strlen(m.body) + 1];
		strcpy(body, m.body);
	}
	else
		body = 0;
	if (strlen(m.from) > 0) //不是空串
		strcpy(from, m.from);
	else
		from[0] = '\0';
	if (strlen(m.to) > 0)
		strcpy(to, m.to);
	else
		to[0] = '\0';
}
Message::~Message() {
	if (body)
		delete[] body;
}
//发送短消息，发送成功返回1，失败返回0
int Message::send() {
	if (body && strlen(body) > 0 && strlen(from) > 0 && strlen(to) > 0) {
		cout << from << "  发送给  " << to << ":    " << body << endl;
		return 1;
	}
	else
		return 0;
}

//main函数除最后面部分，其他部分不要更改，做题过程中可以把未完成部分注释掉，一点点放开注释。
int main() {
	Message ms1("hello", "zhangsan", "lisi");
	if (ms1.send())
		cout << "发送成功" << endl;
	//完成以上部分合计得10分
	Message ms2("hello");
	if (ms2.send())
		cout << "发送成功" << endl;
	else
		cout << "发送失败" << endl;
	//完成以上部分合计得20分
	Message ms3 = ms1;
	if (ms3.send())
		cout << "发送成功" << endl;
	else
		cout << "发送失败" << endl;
	//完成以上部分合计得30分
}
