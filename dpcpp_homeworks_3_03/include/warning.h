#pragma once
#include <iostream>

#include "LogMessage.h"

class Warning : public LogMessage
{
private:
	LogMessage* next_=nullptr;
public:
	void type(Type t) const override
	{
		switch (t)
		{
			case Type::warning:
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
		std::string_view message = "It's warning message!\n";
		return message;
	}
};