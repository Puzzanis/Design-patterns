#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "observer.h"

class Logs
{
private:
	std::vector<Observer*> observer_;
public:
	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatalError(const std::string& message) const;

	void add_observer(Observer* observer);
	void remove_observer(Observer* observer);

	void notify_warning(const std::string& message) const;
	void notify_error(const std::string& message) const;
	void notify_fatalError(const std::string& message) const;
	
};
