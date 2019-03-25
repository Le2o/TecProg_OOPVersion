#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include "Language.h"

namespace Filippov
{
	class Procedural : public Language
	{
	public:
		Procedural() {/**/}
		void Input(ifstream &fin);
		void Output(ofstream &fout);

		virtual void Multi_Method(Language *other, ofstream &fout);
		virtual void Multi_Method_Procedural(ofstream &fout);
		virtual void Multi_Method_OOP(ofstream &fout);
	private:
		bool abstract_type;
	};
}

#endif // !PROCEDURAL_H