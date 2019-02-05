#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Filippov
{
	class Object_oriented : public Language
	{
		//unsigned short int year_of_development;
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	public:
		Object_oriented() {/**/}
		void Input(ifstream &fin);
		void Output(ofstream &fout);
	};
}

#endif // !OOP_H