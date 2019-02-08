#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	class LinkedList
	{
		struct Node
		{
			Language *language;
			Node *Next;//указатель на следующий элемент в списке
			Node *Prev;//указатель на предыдущий элемент в списке
		};
	public:
		LinkedList();
		~LinkedList();

		size_t GetSize();
		Node* GetFirst();

		void LinkedList_Input(ifstream &fin);
		void LinkedList_Output(ofstream &fout);

		void Only_Procedural(ofstream &fout);

		void Sort_List();
	private:
		Node *First;//указатель на первый элемент в связном списке
		Node *Last;//указатель на последний элемент в связном списке
		size_t SizeList;

		void Swap(Node *first, Node *second);
	};
}

#endif // !LINKEDLIST_H