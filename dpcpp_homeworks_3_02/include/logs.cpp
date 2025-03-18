#include "logs.h"


void Logs::add_observer(Observer* observer)
{
	observer_.emplace_back(observer);
}

void Logs::remove_observer(Observer* observer)
{
	auto it = remove(observer_.begin(), observer_.end(), observer);
	observer_.erase(it, observer_.end());
}

void Logs::warning(const std::string& message) const
{
	notify_warning(message);
}

void Logs::error(const std::string& message) const
{
	notify_error(message);
}

void Logs::fatalError(const std::string& message) const
{
	notify_fatalError(message);
}

void Logs::notify_warning(const std::string& message) const
{
	for (Observer* obs : observer_)
	{
		obs->onWarning(message);
	}
}

void Logs::notify_error(const std::string& message) const
{
	for (Observer* obs : observer_)
	{
		obs->onError(message);
	}
}

void Logs::notify_fatalError(const std::string& message) const
{
	for (Observer* obs : observer_)
	{
		obs->onFatalError(message);
	}
}