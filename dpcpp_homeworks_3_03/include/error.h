#pragma once
#include <iostream>
#include "LogMessage.h"
#include "LogHandler.h"



class Error :public LogHandler
{
private:
	LogHandler* next_;
	std::string path_;
public:
	Error(std::string& path) : path_{ path } {}

	
	void setNext(LogHandler* handler) override
	{
		next_ = handler;
	};

	void receiveMessage(LogMessage* logMessage) override
	{
		if (logMessage->type() == Type::error)
		{

			std::cout << "processing of writing to a file..." << std::endl;
			std::cout << "Error! -> " << "writing to a file '" << path_ << "': " << logMessage->message() << std::endl;
			std::cout << '\n';
		}
		else if (next_ != nullptr)
		{
			next_->receiveMessage(logMessage);
		}
		else
		{
			std::cout << "Unknown method" << std::endl;
		}
	};
};
