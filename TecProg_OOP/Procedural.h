#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include "Language.h"

namespace Filippov
{
	class Procedural : public Language
	{
	public:
		Procedural() {/**/}
		bool Input(ifstream &fin);
		void Output(ofstream &fout);
		void Only_Procedural(ofstream &fout);
		virtual void Multi_Method(Language *other, ofstream &fout);
		virtual void Multi_Method_Procedural(ofstream &fout);
		virtual void Multi_Method_OOP(ofstream &fout);
		virtual void Multi_Method_Functional(ofstream &fout);
	private:
		bool abstract_type;
	};
}

#endif