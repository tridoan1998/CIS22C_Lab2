///**
//
//* Tri Doan
//
//* CIS 22C, Lab 2
//
//*/
//
//#include <iostream>
//#include "List.h"
//using namespace std;
//
//int main()
//{
//
//	List<char> L5;
//
//  cout << "**Testing Print and insertStart**\n";
//	cout << "Should print out an empty line: \n";
//	L5.print();
//	L5.insertStart('a');
//  cout << "**Testing offEnd, pointIterator, and insertIterator**\n";
//	L5.pointIterator();
//	cout << "should print out 0 if Iterator point to the list.\n" << L5.offEnd() << endl;
//	cout << "Should print out one word 'a' for L5 list now.\n";
//	L5.print();
//	cout << "Should print out one word 'a' and 'b' for L5 list now." <<endl;
//	L5.insertIterator('b');
//	L5.print();
//	cout << endl;
//    cout << "**Testing getIterator and advanceIterator**\n";
//	cout << "Should print out 'a'\n" << L5.getIterator() << endl;
//	L5.advanceIterator();
//	cout << "Should print out 'b' for L5 list now." <<endl;
//	cout << L5.getIterator() << endl << endl;
//    cout << "**Testing reverseIterator and deleteIterator**\n";
//	L5.reverseIterator();
//	cout << "Should print out 'a' again." <<endl;
//	cout << L5.getIterator() <<endl;
//	L5.deleteIterator();
//	cout << "Should print out 'The list is off end'.\n";
//	cout << L5.getIterator();
//
//}

						//TEST RESULT
///*
//**Testing Print and insertStart**
//Should print out an empty line:
//
//**Testing offEnd, pointIterator, and insertIterator**
//should print out 0 if Iterator point to the list.
//0
//Should print out one word 'a' for L5 list now.
//a
//Should print out one word 'a' and 'b' for L5 list now.
//ab
//
//**Testing getIterator and advanceIterator**
//Should print out 'a'
//a
//Should print out 'b' for L5 list now.
//b
//
//**Testing reverseIterator and deleteIterator**
//Should print out 'a' again.
//a
//Should print out 'The list is off end'.
//The list is off end.
//*/
//
//
//
