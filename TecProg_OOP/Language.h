#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <fstream>

using namespace std;

namespace Filippov
{
	class Language
	{
	protected:
		unsigned short int year_of_development;
	public:
		static Language* Language_Input(ifstream &fin);
		virtual void Input(ifstream &fin) = 0;
		virtual void Output(ofstream &fout) = 0;
	};
}

#endif // !LANGUAGE_H