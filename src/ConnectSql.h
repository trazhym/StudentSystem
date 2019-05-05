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
	 * @brief				连接mysql数据库
	 */
	int connect()const;
	virtual ~ConnectSql();
};

} /* namespace std */

#endif /* SRC_CONNECTSQL_H_ */
