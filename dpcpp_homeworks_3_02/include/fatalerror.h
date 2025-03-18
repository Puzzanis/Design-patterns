#pragma once
#include <iostream>

#include "observer.h"

class FatalError : public Observer
{
private:
	std::string path_;
public:
	FatalError(std::string& path) : path_{ path } {}

	void onWarning(const std::string& message) override
	{
		std::cout << "Fatal error! -> " << message << std::endl;
		std::cout << "processing of writing to a file..." << std::endl;
		std::cout << "Fatal error! -> " << "writing to a file '" << path_ << "': " << message << std::endl;
		std::cout << '\n';
	}
};
