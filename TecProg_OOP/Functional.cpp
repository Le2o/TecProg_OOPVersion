#include "Functional.h"

void Filippov::Functional::Input(ifstream &fin)
{
	Filippov::Language::Input(fin);
	unsigned short int temp;
	fin >> lazy_calculations;
	fin >> temp;
	switch (temp)
	{
	case 1:
		type = Functional::typification::STRICT;
		break;
	case 2:
		type = Functional::typification::DYNAMIC;
		break;
	default:
		break;
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