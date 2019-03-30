#include "OOP.h"
#include <string>

bool Filippov::Object_Oriented::Input(ifstream &fin)
{
	if (!Filippov::Language::Input(fin))
	{
		return false;
	}
	
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	int state = stoi(temp);
	switch (state)
	{
	case 1:
		number = Object_Oriented::inheritance::SINGLE;
		return true;
	case 2:
		number = Object_Oriented::inheritance::MULTIPLE;
		return true;
	case 3:
		number = Object_Oriented::inheritance::INTERFACE;
		return true;
	default:
		return false;
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

void Filippov::Object_Oriented::Multi_Method(Language *other, ofstream &fout)
{
	other->Multi_Method_OOP(fout);
}

void Filippov::Object_Oriented::Multi_Method_Procedural(ofstream &fout)
{
	fout << "Procedural and OOP." << endl;
}

void Filippov::Object_Oriented::Multi_Method_OOP(ofstream &fout)
{
	fout << "OOP and OOP." << endl;
}

void Filippov::Object_Oriented::Multi_Method_Functional(ofstream &fout)
{
	fout << "Functional and OOP." << endl;
}
