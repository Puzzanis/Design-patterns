#pragma once
#include <iostream>

#include "LogMessage.h"
#include "LogHandler.h"

class FatalError : public LogHandler
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
		if (logMessage->type() == Type::fatalError)
		{

			std::cout << "Fatal error: " << logMessage->message() << std::endl;
			throw std::runtime_error("FATAL_ERROR!");
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