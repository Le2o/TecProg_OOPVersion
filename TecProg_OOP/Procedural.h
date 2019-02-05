#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include "Language.h"

namespace Filippov
{
	class Procedural : public Language
	{
		//unsigned short int year_of_development;
		bool abstract_type;
	public:
		Procedural() {/**/}
		void Input(ifstream &fin);
		void Output(ofstream &fout);
	};
}

#endif // !PROCEDURAL_H