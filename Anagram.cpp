/**

* Tri Doan

* CIS 22C, Lab 2
*
*/
/*
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char save;
	char save2;
	string again2;
	int num1, num2;
	List<char> L1;
	char c;
	int counter = 1;
	string input;
	string again3;
	cout << "Welcome to the Anagram Arranger!" << endl << endl;
	cout << "Please enter a word: ";
	getline(cin, input);
	c = input[0];
	L1.insertStart(c);
	L1.pointIterator();
	for( counter = 1; counter <input.length(); counter++)
	{
		c = input[counter];
		L1.insertIterator(c);
		L1.advanceIterator();
	}
do{
		L1.printNumberedList();
		cout << "Enter the position numbers of the two letters you wish to swap: ";
		cin >> num1;
		cin >> num2;
		while( num1> L1.getSize() || num2 > L1.getSize()|| num1 >= num2)
		{
			cout << "Invalid entry!\n\n";
			L1.printNumberedList();
			cout << "Enter the position numbers of the two letters you wish to swap: ";
			cin >> num1;
			cin >> num2;

		}
		cout << endl;
		L1.print();
		for(int counter = 1; counter <= input.length(); counter++)
		{

			if(num1 == counter || num2 == counter)
			{
				cout << "^";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl <<endl;
		cout << "Are these the letters you wish to swap? (y/n): " << endl;
		cin >> again2;
		if(again2 == "n" || again2 == "N" || again2 == "no")
		{
			L1.printNumberedList();
		}
		else if(again2 =="y" || again2 == "Y" || again2 == "yes"|| again2 =="Yes")
		{
			L1.pointIterator();
			for(int i=1; i<num1; i++)
			{
				L1.advanceIterator();
			}
				save = L1.getIterator();

			L1.pointIterator();
			for (int i =1; i <num2; i++)
			{
				L1.advanceIterator();
			}
				save2 = L1.getIterator();

			L1.insertIterator(save);
			L1.deleteIterator();

			L1.pointIterator();
			for(int i=1; i<num1; i++)
				{
					L1.advanceIterator();
				}
			L1.insertIterator(save2);
			L1.deleteIterator();

			cout << "The new word is: ";
			L1.print();
		}
		cout << "Want to keep rearranging? (y/n): ";
		cin >> again3;
		if(again3 == "n" || again3 == "N" || again3 == "no")
		{
			cout  << "Bye!";
			exit(0);
		}

}while(again3 == "Y" || again3 =="y"|| again3 == "yes");
}
*/
