#include <iostream>
#include <vector>

#include "./include/LogHandler.h"
#include "./include/LogMessage.h"
#include "./include/error.h"
#include "./include/warning.h"
#include "./include/fatalError.h"
#include "./include/unknownMessage.h"


int main()
{
	std::string path = "c:\\temp";
	LogHandler* errors = new Error(path);
	LogHandler* warnings = new Warning();
	LogHandler* fatalError = new FatalError();
	LogHandler* unknownMessage = new UnknownMessage();
	warnings->setNext(errors);
	errors->setNext(unknownMessage);
	unknownMessage->setNext(fatalError);

	LogMessage wlm(Type::warning, "Warning message");
	LogMessage elm(Type::error, "Error message");
	LogMessage felm(Type::fatalError, "Fatal error!");
	LogMessage umlm(Type::unknownMessage, "Unknow error message");

	std::vector<LogMessage> LM = { wlm, elm, umlm, felm };

	for (auto lm : LM) {
		try
		{
			warnings->receiveMessage(&lm);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
