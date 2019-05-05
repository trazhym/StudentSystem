/*
 * Student.cpp
 *
 *  Created on: 2019年5月5日
 *      Author: zhang
 */

#include "Student.h"

namespace stu {

Student::Student(int id, string name, string sex) {
	// TODO Auto-generated constructor stub
	ID_ = id;
	Name_ = name;
	Sex_ = sex;

}

//打印学生信息
void Student::displsyStuInfo()
{
	cout<<"您要查询的学生信息如下："<<endl;
	cout<<"ID="<<ID_<<"\tName="<<Name_<<"\tSex="<<Sex_<<endl;
}
Student::~Student() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
