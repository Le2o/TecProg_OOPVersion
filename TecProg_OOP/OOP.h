#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Filippov
{
	class Object_Oriented : public Language
	{
	public:
		Object_Oriented() {/**/}
		bool Input(ifstream &fin);
		void Output(ofstream &fout);
		virtual void Multi_Method(Language *other, ofstream &fout);
		virtual void Multi_Method_Procedural(ofstream &fout);
		virtual void Multi_Method_OOP(ofstream &fout);
		virtual void Multi_Method_Functional(ofstream &fout);
	private:
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};
}

#endif