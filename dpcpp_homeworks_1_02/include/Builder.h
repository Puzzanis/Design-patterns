#pragma once

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

	SqlSelectQueryBuilder& AddColumn(std::string columnName) noexcept
	{
		if (query_.column.empty())
		{
			query_.column = columnName;
		}
		else
		{
			query_.column += ", " + columnName;
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) noexcept
	{
		query_.where.emplace_back(std::make_pair(key, value));
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

		query_.sqlToSend += " FROM " + query_.table;

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