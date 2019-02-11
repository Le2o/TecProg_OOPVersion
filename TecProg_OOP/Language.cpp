#include "Language.h"
#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"

Filippov::Language* Filippov::Language::Language_Input(ifstream &fin)
{
	Language *language;
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		language = new Procedural;
		break;
	case 2:
		language = new Object_oriented;
		break;
	case 3:
		language = new Functional;
		break;
	default:
		return 0;
	}
	language->Input(fin);
	return language;
}

void Filippov::Language::Input(ifstream &fin)
{
	fin >> year_of_development;
}

void Filippov::Language::Output(ofstream &fout)
{
	fout << "Year of development = " << year_of_development << endl;
}