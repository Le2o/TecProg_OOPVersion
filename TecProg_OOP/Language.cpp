#include "Language.h"
#include "Procedural.h"
#include "OOP.h"

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
	default:
		return 0;
	}
	language->Input(fin);
	return language;
}

void Filippov::Language::Input(ifstream &fin)
{
	fin >> year_of_development;
	fin >> reference;
}

void Filippov::Language::Output(ofstream &fout)
{
	fout << "Year of development = " << year_of_development
		<< ", The number of references of this language on the Internet = " << reference << endl;
}