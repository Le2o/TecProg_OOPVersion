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

void Filippov::LinkedList::Only_Procedural(ofstream &fout)
{
	Node *current = First;
	fout << "Only Procedural languages." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		current->language->Only_Procedural(fout);
		current = current->Next;
	}

	fout << endl;
}


void Filippov::LinkedList::Sort_List()
{
	if (SizeList < 2)
		return;

	Node *current = First;

	bool flag = false;

	do
	{
		current = First;
		flag = false;
		for (size_t i = 0; i < (SizeList - 1); ++i)
		{
			if (current->language->Compare(*current->Next->language))
			{
				Swap(current, current->Next);
				flag = true;
			}
			else
			{
				current = current->Next;
			}
		}
	} while (flag);
}

void Filippov::LinkedList::Swap(Node *first, Node *second)
{
	if ((first->Prev == NULL) && (second->Next == NULL))//если в списке всего 2 элемента, но нам приспичило поменять их местами
	{
		First = second;
		Last = first;
		first->Prev = second;
		second->Next = first;
		first->Next = NULL;
		second->Prev = NULL;
		return;
	}
	if ((first->Prev == NULL) && (second->Next != NULL))//если мы меняем местами первый и второй элемент списка, в котором 3 и более элементов !(first->Prev)
	{
		first->Next = second->Next;
		first->Prev = second;
		second->Next->Prev = first;
		second->Next = first;
		second->Prev = NULL;
		First = second;
		return;
	}
	if ((first->Prev != NULL) && (second->Next == NULL))//если мы меняем местами предпоследний и последний элемент списка, в котором 3 и более элементов !(second->Next)
	{
		second->Prev = first->Prev;
		first->Prev = second;
		first->Next = NULL;
		second->Next = first;
		second->Prev->Next = second;
		Last = first;
		return;
	}
	if ((first->Prev != NULL) && (second->Next != NULL))//если мы меняем каких-то два элемента, находящихся в середине списка, в котором 4 и более элемента(например второй и третий, если в списке 4 элемента)
	{
		first->Next = second->Next;
		second->Prev = first->Prev;
		second->Next = first;
		first->Prev = second;
		second->Prev->Next = second;
		first->Next->Prev = first;
		return;
	}
}