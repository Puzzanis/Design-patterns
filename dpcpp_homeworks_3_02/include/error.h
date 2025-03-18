#pragma once
#include <iostream>

#include "observer.h"

class Error : public Observer
{
private:
	std::string path_;
public:
	Error(std::string& path) : path_{ path } {}

	void onWarning(const std::string& message) override
	{
		std::cout << "processing of writing to a file..." << std::endl;
		std::cout << "Error! -> " << "writing to a file '" << path_ << "': " << message << std::endl;
		std::cout << '\n';
	}
};
