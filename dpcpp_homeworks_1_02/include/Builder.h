#include <iostream>
#include "Query.h"


class SqlSelectQueryBuilder
{
private:
	SQLQuery query_;

public:
	SqlSelectQueryBuilder& AddFrom(std::string tableName) noexcept
	{
		query_.table = tableName;
		return *this;
	}

	SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>& columns) noexcept
	{
		if (columns.empty())
		{
			query_.column += "*";
		}
		else
		{
			query_.column += columns[0];
			for (int i = 1; i < columns.size(); ++i)
			{
				query_.column += ", " + columns[i];
			}
			query_.column += " ";
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
	{
		for (auto [key, value] : kv)
		{
			query_.where.emplace_back(make_pair(key, value));
		}
		return *this;
	}

	std::string BuildQuery() noexcept
	{
		if (query_.column.empty())
		{
			query_.sqlToSend = "\"SELECT * ";
		}
		else
		{
			query_.sqlToSend = "\"SELECT " + query_.column;
		}

		query_.sqlToSend += "FROM " + query_.table;

		if (!query_.where.empty())
		{
			query_.sqlToSend += " WHERE ";
			bool first{ true };
			for (auto elem : query_.where)
			{
				if (!first)
				{
					query_.sqlToSend += " AND ";
				}
				query_.sqlToSend += elem.first + "=" + elem.second;
				first = false;
			}

		}
		query_.sqlToSend += ";\"";


		return query_.sqlToSend;
	}

};