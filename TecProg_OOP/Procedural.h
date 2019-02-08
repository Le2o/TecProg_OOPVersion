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
		void Only_Procedural(ofstream &fout);
	private:
		bool abstract_type;
	};
}

#endif // !PROCEDURAL_H