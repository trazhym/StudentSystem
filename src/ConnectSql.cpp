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
int ConnectSql::connect(string sqlString)const
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
	else
	{
		cout<<"connect success"<<endl;
	}
	if(mysql_query(&mysql, sqlString.c_str()) == 1)
	{
		cout<<"查询数据失败"<<mysql_error(&mysql)<<endl;
	}
	else
	{
		cout<<"查询数据成功"<<endl;
		//查询数据结果存放到结果集里
		result = mysql_store_result(&mysql);
		if(mysql_num_rows(result) != 0)
		{
			int numRows = mysql_num_rows(result);
			int numFields = mysql_num_fields(result);
			cout<<"一共"<<numRows<<"条数据"<<"每条数据"<<numFields<<"个字段"<<endl;
			while((row = mysql_fetch_row(result)))
			{
				for(int i=0; i<numFields; i++)
				{
					cout<<row[i]<<"\t";
				}
			}
		}
		else
		{
			cout<<"查询数据为空，请添加数据到表内"<<endl;
		}
		mysql_free_result(result);

	}
	mysql_close(&mysql);                                 // 释放数据库连接</p>
	mysql_server_end();
	return SUCCESS;
}
ConnectSql::~ConnectSql() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
