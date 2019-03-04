#include "OOP.h"

void Filippov::Object_Oriented::Input(ifstream &fin)
{
	Filippov::Language::Input(fin);
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		number = Object_Oriented::inheritance::SINGLE;
		break;
	case 2:
		number = Object_Oriented::inheritance::MULTIPLE;
		break;
	case 3:
		number = Object_Oriented::inheritance::INTERFACE;
		break;
	default:
		break;
	}
}

void Filippov::Object_Oriented::Output(ofstream &fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (number)
	{
	case Object_Oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_Oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_Oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
	Filippov::Language::Output(fout);
}