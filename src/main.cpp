#include "Student.h"
#include "ConnectSql.h"

using namespace stu;
int main()
{
	string user,passwd;
	cout<<"*********欢迎来到学生管理系统**********"<<endl;
	cout<<"请输入用户名：";
	cin>>user;
	cout<<"请输入密码：";
	cin>>passwd;
	ConnectSql con;
	con.login(user,passwd);
	return 0;
}



