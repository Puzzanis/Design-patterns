#pragma once
#include <exception>
#include <iostream>

#include "LogMessage.h"

class FatalError : public LogMessage
{
private:
	LogMessage* next_ = nullptr;
public:
	void type(Type t) const override
	{
		switch (t)
		{
		case Type::fatalError:
			std::cout << message();
			break;
		default:
			if (next_ != nullptr)
			{
				next_->type(t);
			}
			break;
		}
	}

	void set_next_handler(LogMessage* handler) override
	{
		next_ = handler;
	}

	const std::string_view& message() const override
	{
		try
		{
			throw std::runtime_error("It's fatal error message!\n");
		}
		catch (std::exception& ex) 
		{
			std::cout << ex.what();
			exit(1);
		}
	}
};