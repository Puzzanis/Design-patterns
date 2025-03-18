#include <iostream>
#include <string>
#include "./include/error.h"
#include "./include/fatalerror.h"
#include "./include/logs.h"
#include "./include/warning.h"

int main()
{
	std::string path {"c://temp"};
	Logs log;
	Warning warning;
	Error error(path);
	FatalError fatalError(path);

	log.add_observer(&warning);
	log.add_observer(&error);
	log.add_observer(&fatalError);

	std::string message{ "It's warning!" };
	log.warning(message);

	message = "It's error!";
	log.error(message);

	message = "It's fatal error!";
	log.fatalError(message);

	log.remove_observer(&fatalError);

	message = "It's warning 1!" ;
	log.warning(message);

	message = "It's error 1!";
	log.error(message);
	
	message = "It's fatal error 1!";
	log.fatalError(message);


	return 0;
}
