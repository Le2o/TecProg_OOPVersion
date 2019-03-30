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
		static Language *Language_Input(ifstream &fin);
		virtual bool Input(ifstream &fin);
		virtual void Output(ofstream &fout);
		virtual void Only_Procedural(ofstream &fout);
		int Past_Years();
		bool Compare(Language &second);
		virtual void Multi_Method(Language *other, ofstream &fout) = 0;
		virtual void Multi_Method_Procedural(ofstream &fout) = 0;
		virtual void Multi_Method_OOP(ofstream &fout) = 0;
		virtual void Multi_Method_Functional(ofstream &fout) = 0;
	private:
		unsigned int year_of_development;
		unsigned long long int reference;
	};
}

#endif