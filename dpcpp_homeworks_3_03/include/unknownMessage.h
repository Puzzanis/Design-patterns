#pragma once
#include <iostream>

#include "LogMessage.h"

class UnknownMessage : public LogMessage
{
private:
	LogMessage* next_ = nullptr;
public:
	void type(Type t) const override
	{
		switch (t)
		{
		case Type::unknownMessage:
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
		std::string_view message = "It's unknown message!\n";
		try
		{
			throw (message);
		}
		catch (...)
		{
			return message;
		}
	}
};