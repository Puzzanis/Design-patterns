#include <iostream>
#include "./include/Builder.h"

using namespace std;

int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn({ "id", "name", "phone" });

	std::map<std::string, std::string>where
	{
		{ "id", "42" }, { "phone", "424567890" }, { "name", "'Max'" }
	};

	query_builder.AddWhere(where);
	query_builder.AddFrom("students");

	std::cout << query_builder.BuildQuery() << std::endl;

	return 0;
}
