#pragma once
#include <iostream>

#include "LogMessage.h"
#include "LogHandler.h"

class UnknownMessage : public LogHandler
{
private:
	LogHandler* next_;
public:
	void setNext(LogHandler* handler) override
	{
		next_ = handler;
	}

	void receiveMessage(LogMessage* logMessage) override
	{
		if (logMessage->type() == Type::unknownMessage)
		{
			throw std::runtime_error("UNKNOW_ERROR: Message isn't handled\n");
		}
		else if (next_ != nullptr)
		{
			next_->receiveMessage(logMessage);
		}
		else
		{
			std::cout << "Unknown method" << std::endl;
		}
	}
};