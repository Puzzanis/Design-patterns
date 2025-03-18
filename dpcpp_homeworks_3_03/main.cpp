#include <iostream>

#include "./include/LogMessage.h"
#include "./include/error.h"
#include "./include/warning.h"
#include "./include/fatalError.h"
#include "./include/unknownMessage.h"


using namespace std;

int main()
{
	Type typeMessage;
	LogMessage* warnings = new Warning();
	LogMessage* errors = new Error("c:\\temp");
	LogMessage* fatalError = new FatalError();
	LogMessage* unknownMessage = new UnknownMessage();

	warnings->set_next_handler(errors);
	errors->set_next_handler(unknownMessage);
	unknownMessage->set_next_handler(fatalError);

	warnings->type(Type::warning);
	warnings->type(Type::error);
	warnings->type(Type::unknownMessage);
	warnings->type(Type::fatalError);
	

	cout << "Hello CMake." << endl;
	return 0;
}
