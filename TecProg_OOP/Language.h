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
		virtual void Input(ifstream &fin) = 0;
		virtual void Output(ofstream &fout) = 0;
		int Past_Years();
		bool Compare(Language &second);

		virtual void Only_Procedural(ofstream &fout);
	private:
		unsigned short int year_of_development;
		int reference;
	};
}

#endif // !LANGUAGE_H