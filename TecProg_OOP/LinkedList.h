#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	class Linked_List
	{
		struct Node
		{
			Language *language;//указатель на объект списка
			Node *next;//указатель на следующий элемент в списке
			Node *prev;//указатель на предыдущий элемент в списке
		};
	public:
		Linked_List();
		~Linked_List();
		void Linked_List_Input(ifstream &fin);
		void Linked_List_Output(ofstream &fout);
		void Sort_List();
		void Only_Procedural(ofstream &fout);
		void Multi_Method(ofstream &fout);
	private:
		Node *head;//указатель на первый элемент в связном списке
		Node *tail;//указатель на последний элемент в связном списке
		size_t size_list;//размер списка
		void Swap(Node *first, Node *second);
	};
}

#endif