#include "Procedural.h"
#include <string>

bool Filippov::Procedural::Input(ifstream &fin)
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
	if (state > 0)
	{
		abstract_type = true;
	}
	else
	{
		abstract_type = false;
	}
	return true;
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

void Filippov::Procedural::Only_Procedural(ofstream &fout)
{
	Filippov::Procedural::Output(fout);
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

void Filippov::Procedural::Multi_Method_Functional(ofstream &fout)
{
	fout << "Functional and Procedural." << endl;
}
