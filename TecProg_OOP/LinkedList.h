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
			Node *Next;//��������� �� ��������� ������� � ������
			Node *Prev;//��������� �� ���������� ������� � ������
		};
	public:
		LinkedList();
		~LinkedList();

		size_t GetSize();
		Node* GetFirst();

		void LinkedList_Input(ifstream &fin);
		void LinkedList_Output(ofstream &fout);

	private:
		Node *First;//��������� �� ������ ������� � ������� ������
		Node *Last;//��������� �� ��������� ������� � ������� ������
		size_t SizeList;
	};
}

#endif // !LINKEDLIST_H