#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Filippov;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout(argv[2]);

	cout << "Start" << endl;

	Linked_List list;	
	list.Linked_List_Input(fin);
	fout << "Filled container." << endl;
	list.Linked_List_Output(fout);
	
	fout << endl << "Sorted Linked List." << endl;
	list.Sort_List();
	list.Linked_List_Output(fout);

	list.Only_Procedural(fout);
	
	list.~Linked_List();
	fout << "Empty container." << endl;
	list.Linked_List_Output(fout);

	cout << "Stop" << endl;
	return 0;
}