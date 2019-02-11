#include "LinkedList.h"

Filippov::LinkedList::LinkedList()
{
	First = NULL;
	Last = NULL;
	SizeList = 0;
}

Filippov::LinkedList::~LinkedList()
{
	Node *Temp = NULL;
	while (Last != NULL)
	{
		Temp = Last->Prev;
		delete Last;
		Last = Temp;
		--SizeList;
	}
	First = Temp;
}



void Filippov::LinkedList::LinkedList_Input(ifstream &fin)
{
	Node *Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->Next = NULL;

		Temp->language = Language::Language_Input(fin);

		++SizeList;

		if (First == NULL)//если список пустой
		{
			Temp->Prev = NULL;
			First = Last = Temp;
		}
		else//если в списке есть хотя бы 1 элемент
		{
			Temp->Prev = Last;
			Last->Next = Temp;
			Last = Temp;
		}
	}
}

void Filippov::LinkedList::LinkedList_Output(ofstream &fout)
{
	Node *current = First;
	fout << "Container contains " << SizeList << " elements." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		current->language->Output(fout);
		fout << "The number of years that have passed since the year the language was created = "
			<< current->language->Past_Years() << endl << endl;
		current = current->Next;
	}
}