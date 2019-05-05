#include "Student.h"
#include "ConnectSql.h"

using namespace stu;
int main()
{
	ConnectSql con;
	con.connect();
	return 0;
}



