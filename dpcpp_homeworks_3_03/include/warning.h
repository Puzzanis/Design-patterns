#pragma once
#include <iostream>

#include "LogMessage.h"
#include "LogHandler.h"

class Warning : public LogHandler
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
		if (logMessage->type() == Type::warning)
		{
			std::cout << "Warning: " << logMessage->message() << std::endl << std::endl;
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