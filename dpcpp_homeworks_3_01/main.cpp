// dpcpp_homeworks_3_01.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "./include/Log.h"

int main()
{
	LogToConsol consol;
	LogToFile files;

	PrintAnywhere print("Hello world!");
	print.print(consol);
	print.print(files);


	return 0;
}
