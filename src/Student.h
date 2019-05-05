/*
 * Student.h
 *
 *  Created on: 2019年5月5日
 *      Author: zhang
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "Helper.h"

namespace stu {

using namespace std;

class Student {
public:
	/**
	 * @brief			构造函数
	 * @param[id]		学号
	 * @param[name]		姓名
	 * @param[sex]		性别
	 *
	 */
	Student(int id, string name, string sex);

	/**
	 * @brief			打印出学生信息
	 */
	void displsyStuInfo();

	virtual ~Student();
private:
	int ID_;
	string Name_;
	string Sex_;
};

} /* namespace stu */

#endif /* STUDENT_H_ */
