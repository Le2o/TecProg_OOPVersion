#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <fstream>

using namespace std;

namespace Filippov
{
	class Language
	{
	protected:
		Language() {/**/}
	public:
		static Language* Language_Input(ifstream &fin);
		virtual void Input(ifstream &fin);
		virtual void Output(ofstream &fout);
	private:
		unsigned short int year_of_development;
	};
}

#endif // !LANGUAGE_H