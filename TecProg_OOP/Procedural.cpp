#include "Procedural.h"

void Filippov::Procedural::Input(ifstream &fin)
{
	Filippov::Language::Input(fin);
	fin >> abstract_type;
}

void Filippov::Procedural::Output(ofstream &fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	Filippov::Language::Output(fout);
}