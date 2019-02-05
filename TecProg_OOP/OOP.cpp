#include "OOP.h"

void Filippov::Object_oriented::Input(ifstream &fin)
{
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		number = Object_oriented::inheritance::SINGLE;
		break;
	case 2:
		number = Object_oriented::inheritance::MULTIPLE;
		break;
	case 3:
		number = Object_oriented::inheritance::INTERFACE;
		break;
	default:
		break;
	}
}

void Filippov::Object_oriented::Output(ofstream &fout)
{
	fout << "It is Object-oriented programming language: Year of development = " << year_of_development
		<< ", Inheritance is ";
	switch (number)
	{
	case Object_oriented::inheritance::SINGLE:
		fout << "single." << endl;
		break;
	case Object_oriented::inheritance::MULTIPLE:
		fout << "multiple." << endl;
		break;
	case Object_oriented::inheritance::INTERFACE:
		fout << "interface." << endl;
		break;
	default:
		break;
	}
}