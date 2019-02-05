#include "Procedural.h"

void Filippov::Procedural::Input(ifstream &fin)
{
	fin >> abstract_type;
}

void Filippov::Procedural::Output(ofstream &fout)
{
	fout << "It is Procedural programming language: Year of development = " << year_of_development
		<< ", Abstract data types is ";
	if (abstract_type)
	{
		fout << "present." << endl;
	}
	else
	{
		fout << "missing." << endl;
	}
}