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
		current = current->Next;
	}
}

void Filippov::LinkedList::Multi_Method(ofstream &fout)
{
	Node *current_first = First;
	Node *current_second = current_first->Next;

	fout << "Multimethod." << endl;
	for (size_t i = 0; i < SizeList - 1; i++)
	{
		for (size_t j = i + 1; j < SizeList; j++)
		{			
			current_first->language->Multi_Method(current_second->language, fout);
			current_first->language->Output(fout);
			current_second->language->Output(fout);
			current_second = current_second->Next;
		}
		current_first = current_first->Next;
		current_second = current_first->Next;
	}
}