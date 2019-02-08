#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Filippov
{
	class Object_oriented : public Language
	{
	public:
		Object_oriented() {/**/}
		void Input(ifstream &fin);
		void Output(ofstream &fout);
	private:
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};
}

#endif // !OOP_H