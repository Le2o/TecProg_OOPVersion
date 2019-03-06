#include "Functional.h"
#include <string>

bool Filippov::Functional::Input(ifstream &fin)
{
	if (!Filippov::Language::Input(fin))
	{
		return false;
	}
	
	string temp;
	fin >> temp;
	if (temp.length() > 1)
	{
		getline(fin, temp, '\n');
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		getline(fin, temp, '\n');
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		lazy_calculations = true;
	}
	else
	{
		lazy_calculations = false;
	}

	fin >> temp;
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	state = stoi(temp);
	switch (state)
	{
	case 1:
		type = Functional::typification::STRICT;
		return true;
	case 2:
		type = Functional::typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}

void Filippov::Functional::Output(ofstream &fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (lazy_calculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	fout << "Typification is ";
	switch (type)
	{
	case Functional::typification::STRICT:
		fout << "strict, ";
		break;
	case Functional::typification::DYNAMIC:
		fout << "dynamic, ";
		break;
	default:
		break;
	}
	Filippov::Language::Output(fout);
}