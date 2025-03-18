#pragma once
#include <iostream>

#include "LogMessage.h"

class Error : public LogMessage
{
private:
	std::string path_;
	LogMessage* next_ = nullptr;
public:
	Error(const std::string_view& path): path_{ path } {}

	void type(Type t) const override
	{
		switch (t)
		{
		case Type::error:
			std::cout << "processing of writing to a file..." << std::endl;
			std::cout << "writing to a file '" << path_ << ": " << message();
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
		std::string_view message = "It's error message!\n";
		return message;
	}
};