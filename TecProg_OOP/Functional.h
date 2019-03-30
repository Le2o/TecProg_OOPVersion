#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "Language.h"

namespace Filippov
{
	class Functional : public Language
	{
	public:
		Functional() {/**/}
		bool Input(ifstream &fin);
		void Output(ofstream &fout);
		virtual void Multi_Method(Language *other, ofstream &fout);
		virtual void Multi_Method_Procedural(ofstream &fout);
		virtual void Multi_Method_OOP(ofstream &fout);
		virtual void Multi_Method_Functional(ofstream &fout);
	private:
		bool lazy_calculations;
		enum typification
		{
			STRICT,
			DYNAMIC
		} type;
	};
}

#endif