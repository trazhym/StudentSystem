/*
 * ConnectSql.cpp
 *
 *  Created on: 2019年5月5日
 *      Author: zhang
 */

#include "ConnectSql.h"

namespace stu {
using namespace std;

ConnectSql::ConnectSql() {
	// TODO Auto-generated constructor stub

}

//连接mysql数据库,并且执行查询
int ConnectSql::connect(string sqlString, vector<string>& vec)const
{
	//连接mysql数据库
	MYSQL mysql;

	//查询放回结果集
	MYSQL_RES* result;

	//查询返回结果记录数
	MYSQL_ROW row;

	//初始化mysql结构
	mysql_init(&mysql);

//	[mysql]			mysql_init返回的指针
//	[hostname]		要连接的计算机的名字,可以是主机名或者ip
//	[user,passwd]	用户的mysql登录id和密码
//	[db]			要连接的数据库名称
//	[port]			端口号，默认为0，如果不是0，该参数将用作TCP/IP连接的端口号
//	[socket]		socket连接类型，默认为NULL
//	[flag]			通常为0
	if(mysql_real_connect(&mysql, "localhost", "root", "zhang123", "student", 3306, NULL, 0) == NULL)
	{
		//显示错误信息
		cout<<"connect sql error"<<mysql_error(&mysql)<<endl;
	}
//	else
//	{
//		cout<<"connect success"<<endl;
//	}
	if(mysql_query(&mysql, sqlString.c_str()) == 1)
	{
		cout<<"执行sql失败"<<mysql_error(&mysql)<<endl;
	}
	else
	{
//		cout<<"执行sql成功"<<endl;
		//把插入、删除、更新等与查询操作区分开来
		if(sqlString.substr(0,6) != "select")
		{
			mysql_close(&mysql);                                 // 释放数据库连接</p>
			mysql_server_end();
			return SUCCESS;
		}
		//下面是查询操作
		else
		{
			//查询数据结果存放到结果集里
			result = mysql_store_result(&mysql);
			if(mysql_num_rows(result) != 0)
			{
//				int numRows = mysql_num_rows(result);
				int numFields = mysql_num_fields(result);
//				cout<<"一共"<<numRows<<"条数据"<<"每条数据"<<numFields<<"个字段"<<endl;
				while((row = mysql_fetch_row(result)))
				{
					for(int i=0; i<numFields; i=i+2)
					{
						strcat(row[i], row[i+1]);
						vec.push_back(row[i]);
					}
				}
			}
			else
			{
				cout<<"查询数据为空，请添加数据到表内"<<endl;
			}
			mysql_free_result(result);

		}
	}

	mysql_close(&mysql);                                 // 释放数据库连接</p>
	mysql_server_end();
	return SUCCESS;
}


//用户注册
void ConnectSql::regist(string user, string passwd)
{
	//这个vector没有用到
	vector<string> v;
	string sqlString = "insert into user(user,passwd) values ('"+ user + +"','"+ passwd + "')";
	cout<<"插入语句"<<sqlString<<endl;
	connect(sqlString, v);

}

//用户登录
int ConnectSql::login(string user, string passwd)
{
	//存放数据库查询返回的用户名和密码
	vector<string> vec_login;

	//查询行数
	size_t i = 0;

	//查询用户名，存放到vec_user中
	string sql_user = "select user,passwd from user";
	connect(sql_user, vec_login);

	vector<string>::iterator it;
	for(it=vec_login.begin(); it!=vec_login.end(); it++)
	{
		if(strcmp((user + passwd).c_str(),(*it).c_str()) == 0)
		{
			cout<<"登录成功"<<endl;
			return 0;
		}
		else
		{
//			cout<<"用户输入："<<user+passwd<<"数据库"<<*it<<endl;
			i++;
			if(i==vec_login.size())
			{
				cout<<"用户名或密码错误"<<endl;
			}
//			cout<<i<<endl;
		}
	}
	return SUCCESS;
}


ConnectSql::~ConnectSql() {
	// TODO Auto-generated destructor stub
}
} /* namespace std */
