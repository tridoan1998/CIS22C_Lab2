/**

* Tri Doan

* CIS 22C, Lab 2

*/

#ifndef LIST_H_
#define LIST_H_

/*
#include <iostream>
#include <assert.h>
#include <cstddef> //for NULL
using namespace std;

template <class listdata> // list stores generic listdata, not any specific C++ type
class List {

private:
    struct Node {
        listdata data;
        Node* linknext;
        Node* linkprevious;

        Node(listdata newData){
            data = newData;
            linknext = NULL;
            linkprevious = NULL;
        }
    };

    Node* start;
    Node* stop;
    Node* Iterator;  //the iterator
    int size;

public:

    /**Constructors and Destructors

    List();
    //Default constructor; initializes and empty list
    //Postcondition: display the empty list.

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: delete the list and free memory.

    List(const List& list);
    //Copy constructor. Initializes list to have the same elements as another list (makes a copy of the list object)
    //Postcondition: a copy of the linked list is made.


    /**Accessors

    listdata getStart() const;
    //Returns the data of the first element
    //Postcondition: Returns the first data in the list
    //Precondition: make sure the list is not empty.

    listdata getStop() const;
    //Returns the data of the last element
    //Postcondition: Returns the last data in the list
    //Precondition: make sure the list is not empty and the node point to NULL.

    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator
    //Precondition: There is at least one element in the linked list

    bool isEmpty() const;
    //Determines whether a list is empty.
    //Postcondition: telling users if the list is empty or not.
    //Precondition: creating a list to check.

    bool offEnd() const;
    //Returns whether the iterator is off the end of the list, i.e. is NULL
    //Postcondition:
	//Precondition:

    int getSize() const;
    //Return the size of the list.
    //Postcondition: Returns the size of the list.
    //Precondition: creating a list to check.

    bool operator==(const List& list);
    //Compares this list to see if it contains the same data, in the same order as another list.

    /**Manipulation Procedures
    void removeStop();
    //Removes the value of the last data in the list
    //Precondition: 3 conditions. size is 0, size is 1, and size is greater than 1.
    //Postcondition: if size is 0 then print out error message. If there is only one node then make the node start and stop. Else remove the last item on the list.

    void removeStart();
    //Removes the value of the first data in the list
    //Precondition: 3 conditions. size is 0, size is 1, and size is greater than 1.
    //Postcondition: if size is0 then print out error message. If size is 1 delete the whole list and if size > 1 print out the list without its print item.

    void insertStop (listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Precondition: the list has size of 0 or higher.
    //Postcondition: print out the list with a new data.

    void insertStart(listdata data);
    //Inserts a new data at the start of the list
    //Precondition: the list has size of 0 or higher.
    //Postcondition: print out the list with a new data at the beginning. If the list is empty, the new data becomes both first and last

    void pointIterator();
    //Moves the iterator to the start of the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: a new element is added after where iterator is located.
    //Precondition: There is an iterator.

    void insertIterator(listdata data);
    //Inserts an element after the node currently pointed to by the iterator
    //Precondition: the iterator is pointing to an element
    //Postcondition: a new element is added after where iterator is located

    void deleteIterator();
    //Removes the element currently pointed to by the iterator. Iterator then points to NULL.
    //Precondition: there is an element in the list and the iterator is pointing to it.
    //Postcondition: the element pointing by iterator is removed.

    void advanceIterator();
    //Moves the iterator up by one node towards stop
    //Precondition: has no effect if the iterator is offend or the list is empty
    //Postcondition: the iterator is pointing to the next element

    void reverseIterator();
	//Moves the iterator down by one node towards start.
    //Precondition:has no effect if the iterator is offend or the list is empty
    //Postcondition: the iterator is pointing to the previous element


    /**Additional List Operations
    void print() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty.

    void printNumberedList() const;
    //Prints the contents of the linked list to the screen in the format #: <element> followed by a newline
    //Similar to the print function but with the format #: <element> go along.

    void swap(int num1, int num2);
    //Swap two element in the list.
    //Precondition: Iterator points to a list.
    //Postcondition: The two elements selected are swap.
};

template<class listdata>
List<listdata>::List() {
    start = NULL;
    stop = NULL;
    Iterator = NULL;
    size = 0;
}

template<class listdata>
List<listdata>::~List()
{
	Iterator = start;
    Node* temp = NULL;
    while (Iterator != NULL)
    {
        temp = Iterator->linknext; //move a to node after iterator
        delete Iterator; //remove Iterator (you know it is not NULL from if)
        Iterator = temp; //Iterator "catches up" with temp (both point to same place in list)
    }
}



template<class listdata>
List<listdata>::List(const List& list): size(list.size)
    {
    if(list.start == NULL) //If the original list is empty, make an empty list for this list
        {
            start = stop = Iterator = NULL;
        }
        else
        {
            start = new Node(list.start->data); //using second Node constructor
            Node* temp = list.start; //set a temporary node pointer to point at the start of the original list
            Iterator = start; //set iterator to point to start of the new list
        while(temp->linknext != NULL)
        {
            temp = temp->linknext; //advance up to the next node in the original list
            Iterator->linknext = new Node(temp->data); //using node constructor to create a new node with copy of data
            Iterator = Iterator->linknext; //advance to this new node
        }
            stop = Iterator;
            Iterator = NULL;
        }
    }


template<class listdata>
void List<listdata>::print() const
{
    Node* temp = start; //create a temporary iterator
    while (temp != NULL) // make sure node temp is not empty
    {

        cout << temp->data << "";
        temp = temp->linknext;

    }
    cout << endl; //What does this do? ->> this line end the print out function when temp reach NULL.
}


template<class listdata>
void List<listdata>::insertStart(listdata data) {
    if (size == 0) {
        start = stop = new Node(data);
    } else {
        Node* N = new Node(data);
        N->linknext = start;	//set the new node's next field to point to the start
        start->linkprevious = N;
        start = N;		//make the start be the new node
    }
    size++;
}

template<class listdata>
void List<listdata>::insertStop (listdata data)
{
	Node* N = new Node(data); // declare new node to add
	if(size == 0) // empty list
	{
		start = N;
		stop = start;
	}
	else
	{
		N->linkprevious = stop;
		stop->linknext = N;
		stop = N;
	}
	size++;
}

template<class listdata>
void List<listdata>::removeStart()
{
	assert(size != 0);

    if(size == 1)
    {
        delete start;
        start = stop = Iterator = NULL;
        size = 0;
    }
    else
    {
        Node* temp = start;
        start = start->linknext;
        start->linkprevious = NULL;
        delete temp;
        size--;
    }
}

template<class listdata>
void List<listdata>::removeStop()
{
	assert(size != 0);

    if (size == 1) {

        delete stop;
        start = stop = Iterator = NULL;
        size = 0;

    } else {
        Node* temp = stop;	// Create an iterator point to end.
        Iterator = start;	// Iterator point to start.
        while(Iterator->linknext != stop)	// Run until reach stop.
        {
            Iterator = Iterator->linknext;
        }
        stop = Iterator;
        Iterator->linknext = NULL;
        Iterator->linkprevious = stop;
        delete temp;
        size--;
    }
}

template<class listdata>
bool List<listdata>::isEmpty() const	//Determines whether a list is empty.
{
    return size == 0;
}

template<class listdata>
int List<listdata>::getSize() const
{
    return size;
}

template<class listdata>
listdata List<listdata>::getStart() const	//Returns the first element in the list
{
	assert(size != 0);
    return start -> data;
}

template<class listdata>
listdata List<listdata>::getStop() const	//Returns the last element in the list
{
	assert(size != 0);
    return stop -> data;
}

template<class listdata>
listdata List<listdata>::getIterator() const
{
	assert( size != 0);
	if (offEnd()){

		cout << "The list is off end." << endl;
		exit(-1);
	}
	else {

			return Iterator->data;

	}
}

template<class listdata>
bool List<listdata>::offEnd() const
{
	if ( Iterator == NULL)
		return true;
	else
		return false;
}

template<class listdata>
void List<listdata>::pointIterator()
{
	Iterator = start;
}

template<class listdata>
void List<listdata>::insertIterator(listdata data)
{
if (offEnd())
	cout << "The list is off end." << endl;
else if (Iterator == stop)
	insertStop(data);
else
	{
		Node*N = new Node(data);
		N->linknext = Iterator->linknext;
		Iterator->linknext = N;
		N->linkprevious = Iterator;
		N->linknext->linkprevious = N;
		size++;
	}
}
template<class listdata>
void List<listdata>::advanceIterator()
{
	if (offEnd())
		cout << "The list is off end." << endl;
	else
		Iterator = Iterator->linknext;
}

template<class listdata>
void List<listdata>::reverseIterator()
{
	if(offEnd())
		cout << "The list is off end." << endl;
	else
		Iterator = Iterator->linkprevious;
}


template<class listdata>
bool List<listdata>::operator==(const List& list)
{
	if(size!= list.size)
		return false;
	Node* temp1 = start;
	Node* temp2 = list.start;
	while(temp1 != NULL)
	{
		if(temp1->data != temp2->data)
			return false;
		temp1 = temp1->linknext;
		temp2 = temp2->linknext;
	}
	return true;
}

template<class listdata>
void List<listdata>::deleteIterator()
{
	assert(size!=0);
	assert(Iterator != NULL);
		if (Iterator == start)
		{
			removeStart();
			Iterator = NULL;
		}
		else if(Iterator == stop)
		{
			removeStop();
			Iterator = NULL;
		}
		else
		{
			Iterator->linknext->linkprevious = Iterator->linkprevious;
			Iterator->linkprevious->linknext = Iterator-> linknext;
			delete Iterator;
			Iterator = NULL;
			size--;
		}
}

template<class listdata>
void List<listdata>::printNumberedList() const
{
    Node* temp = start; //create a temporary iterator
    int counter = 1;
    while (temp != NULL) // make sure node temp is not empty
    {

        cout << counter << ": " << temp->data << endl;
        temp = temp->linknext;
        counter++;
    }
    cout << endl; //this line end the print out function when temp reach NULL.
}


#endif /* LIST_H_ */

