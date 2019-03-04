#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "Language.h"

namespace Filippov
{
	class Functional : public Language
	{
	public:
		Functional() {/**/}
		void Input(ifstream &fin);
		void Output(ofstream &fout);
	private:
		bool lazy_calculations;
		enum typification
		{
			STRICT,
			DYNAMIC
		} type;
	};
}

#endif // !FUNCTIONAL_H