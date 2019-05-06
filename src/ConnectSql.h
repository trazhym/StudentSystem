/*
 * ConnectSql.h
 *
 *  Created on: 2019年5月5日
 *      Author: zhang
 *      主要实现连接mysql数据库，执行增删改查操作
 */

#ifndef SRC_CONNECTSQL_H_
#define SRC_CONNECTSQL_H_
#include <mysql.h>
#include "Helper.h"

namespace stu {
using namespace std;

class ConnectSql {
public:
	ConnectSql();
	/**
	 * @brief				连接mysql数据库,并执行查询
	 * @param[sqlString]	查询字符串
	 * @param[vec]			查询结果存放到vector中
	 */
	int connect(string sqlString, vector<string>& vec)const;

	/**
	 * 用户注册
	 * @param[user]			用户名
	 * @param[passwd]		密码
	 */
	void regist(string user, string passwd);

	/**
	 * 用户登录校验
	 * @param[user]			用户名
	 * @param[passwd]		密码
	 */
	int login(string user, string passwd);

	virtual ~ConnectSql();
};


} /* namespace std */

#endif /* SRC_CONNECTSQL_H_ */
