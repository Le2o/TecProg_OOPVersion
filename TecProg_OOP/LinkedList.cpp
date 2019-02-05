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
	delete Temp;
}


size_t Filippov::LinkedList::GetSize()
{
	return SizeList;
}

Filippov::LinkedList::Node* Filippov::LinkedList::GetFirst()
{
	return First;
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

		if (First == NULL)//���� ������ ������
		{
			Temp->Prev = NULL;
			First = Last = Temp;
		}
		else//���� � ������ ���� ���� �� 1 �������
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