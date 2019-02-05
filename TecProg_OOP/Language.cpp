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
		fin >> language->year_of_development;
		break;
	case 2:
		language = new Object_oriented;
		fin >> language->year_of_development;
		break;
	default:
		return 0;
	}
	language->Input(fin);
	return language;
}