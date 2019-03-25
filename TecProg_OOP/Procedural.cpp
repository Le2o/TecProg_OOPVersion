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

void Filippov::Procedural::Multi_Method(Language *other, ofstream &fout)
{
	other->Multi_Method_Procedural(fout);
}

void Filippov::Procedural::Multi_Method_Procedural(ofstream &fout)
{
	fout << "Procedural and Procedural." << endl;
}

void Filippov::Procedural::Multi_Method_OOP(ofstream &fout)
{
	fout << "OOP and Procedural." << endl;
}