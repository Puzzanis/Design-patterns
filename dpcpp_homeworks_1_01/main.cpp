#include <iostream>
#include "./include/Builder.h"

using namespace std;

int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	query_builder.AddFrom("students");
	query_builder.AddWhere("phone", "123456");

	std::cout << query_builder.BuildQuery() << std::endl;

	return 0;
}
