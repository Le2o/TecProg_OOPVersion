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

		virtual void Multi_Method(Language *other, ofstream &fout) = 0;
		virtual void Multi_Method_Procedural(ofstream &fout) = 0;
		virtual void Multi_Method_OOP(ofstream &fout) = 0;
	private:
		unsigned short int year_of_development;
	};
}

#endif // !LANGUAGE_H