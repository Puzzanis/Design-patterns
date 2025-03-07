#pragma once

#include <iostream>
#include <map>

struct SQLQuery
{
  std::string column;
  std::string table;
  std::map<std::string, std ::string> where;
  std::string sqlToSend;
};