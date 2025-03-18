#pragma once
#include <iostream>

#include "observer.h"

class Warning: public Observer
{
public:
	void onWarning(const std::string& message) override 
	{
		std::cout << "Warning! -> " << message << std::endl;
		std::cout << '\n';
	}
};
