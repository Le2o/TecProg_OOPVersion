#include "LinkedList.h"

Filippov::Linked_List::Linked_List()
{
	head = NULL;
	tail = NULL;
	size_list = 0;
}

Filippov::Linked_List::~Linked_List()
{
	Node *temp = NULL;
	while (tail != NULL)
	{
		temp = tail->prev;
		delete tail;
		tail = temp;
		--size_list;
	}
	head = temp;
}


void Filippov::Linked_List::Linked_List_Input(ifstream &fin)
{
	Node *temp;
	while (!fin.eof())
	{
		temp = new Node;

		temp->language = Language::Language_Input(fin);
		temp->next = NULL;
		++size_list;

		if (head == NULL)//если список пустой
		{
			temp->prev = NULL;
			head = tail = temp;
		}
		else//если в списке есть хотя бы 1 элемент
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
}

void Filippov::Linked_List::Linked_List_Output(ofstream &fout)
{
	Node *current = head;
	fout << "Container contains " << size_list << " elements." << endl;

	for (size_t i = 0; i < size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			current->language->Output(fout);
			fout << "The number of years that have passed since the year the language was created = "
				<< current->language->Past_Years() << endl;
		}
		current = current->next;
	}
}


void Filippov::Linked_List::Only_Procedural(ofstream &fout)
{
	Node *current = head;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << endl;
			continue;
		}
		current->language->Only_Procedural(fout);
		current = current->next;
	}

	fout << endl;
}


void Filippov::Linked_List::Sort_List()
{
	if (size_list < 2)
	{
		return;
	}

	Node *current = head;
	bool flag = false;
	do
	{
		current = head;
		flag = false;
		for (size_t i = 0; i < (size_list - 1); ++i)
		{
			if (current->language->Compare(*current->next->language))
			{
				Swap(current, current->next);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}

void Filippov::Linked_List::Swap(Node *first, Node *second)
{
	if ((first->prev == NULL) && (second->next == NULL))//если в списке всего 2 элемента, но нам приспичило поменять их местами
	{
		head = second;
		tail = first;
		first->prev = second;
		second->next = first;
		first->next = NULL;
		second->prev = NULL;
		return;
	}
	if ((first->prev == NULL) && (second->next != NULL))//если мы меняем местами первый и второй элемент списка, в котором 3 и более элементов !(first->Prev)
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		head = second;
		return;
	}
	if ((first->prev != NULL) && (second->next == NULL))//если мы меняем местами предпоследний и последний элемент списка, в котором 3 и более элементов !(second->Next)
	{
		second->prev = first->prev;
		first->prev = second;
		first->next = NULL;
		second->next = first;
		second->prev->next = second;
		tail = first;
		return;
	}
	if ((first->prev != NULL) && (second->next != NULL))//если мы меняем каких-то два элемента, находящихся в середине списка, в котором 4 и более элемента(например второй и третий, если в списке 4 элемента)
	{
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		second->prev->next = second;
		first->next->prev = first;
		return;
	}
}