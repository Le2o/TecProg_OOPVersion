#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"
#include <ctime>
#include <string>

Filippov::Language *Filippov::Language::Language_Input(ifstream &fin)
{
	Language *language;
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length()  > 1)
	{
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	int state = stoi(temp);
	switch (state)
	{
	case 1:
		language = new Procedural;
		break;
	case 2:
		language = new Object_Oriented;
		break;
	case 3:
		language = new Functional;
		break;
	default:
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	if (!language->Input(fin))
	{
		return NULL;
	}
	else
	{
		return language;
	}
}

bool Filippov::Language::Input(ifstream &fin)
{
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() != 4)
	{
		getline(fin, temp, '\n');
		return false;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(fin, temp, '\n');
			return false;
		}
	}
	year_of_development = stoul(temp);

	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(fin, temp, '\n');
			return false;
		}
	}
	reference = stoull(temp);
	return true;
}

void Filippov::Language::Output(ofstream &fout)
{
	fout << "Year of development = " << year_of_development
		<< ", The number of references of this language on the Internet = " << reference << endl;
}


void Filippov::Language::Only_Procedural(ofstream &fout)
{
	fout << endl;
}


int Filippov::Language::Past_Years()
{
	time_t now = time(NULL);
	tm *localtm = localtime(&now);
	return 1900 + localtm->tm_year - year_of_development;
}

bool Filippov::Language::Compare(Language &second)
{
	if (this == NULL && &second != NULL)
	{
		return true;
	}
	if (this != NULL && &second == NULL)
	{
		return false;
	}
	if (this == NULL && &second == NULL)
	{
		return false;
	}
	return Past_Years() < second.Past_Years();
}