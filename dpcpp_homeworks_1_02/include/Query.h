#pragma once

#include <iostream>
#include <map>
#include <vector>

struct SQLQuery
{
	std::string column;
	std::string table;
	std::vector<std::pair<std::string, std::string>> where{};
	std::string sqlToSend;
};