#include "Student.h"
#include "ConnectSql.h"

using namespace stu;
int main()
{
	ConnectSql con;
	con.connect("select * from student");
	return 0;
}



