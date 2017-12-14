
De Anza College CIS

Search this site
Home
CIS36A
CIS22C
CIS22A

Lab 2 (100 pts) 
Due Tuesday, October 10 at 11:20am on Canvas


Part 1: Templating Your List 
For this Lab, you will need to template your List class.
The purpose of templating your list is to allow it hold any type of data (not just ints).
Otherwise, you would need to write a whole new list class for strings, one for chars, one for doubles, or any other type of data you need to store in your list. What a pain!
Fortunately, we can use templating to help us.
Templating makes your list much more flexible by allowing it to store ANY type of data without having to rewrite the class.
You will need to specify that you List holds a generic type of objects (not ints anymore).
To do so, follow these steps:
Step 1: Open up your List.h file and add the following line above your definition of the List class:

    template <class listdata> //list stores generic listdata, not any specific C++ type
    class List {
Also, alter the Node struct to store listdata rather than integer data:
        struct Node
        {
            listdata data;
            Node* linknext;

            Node(listdata newdata): data(newdata), linknext(NULL) {}
        };

Step 2: for EACH function in your list, you will need to alter it so it works with generic data. Make changes like so:
    void insertStart(listdata data); //this function now takes in generic data

    listdata getStart(); //this function now returns generic data
Alter ALL remaining functions prototypes inside your List.h to work with generic listdata, as show above. Note that you will not need to alter functions like getSize which always should return an int. (Why?)
Step 3: Alter the functions inside your List.cpp file that you wrote for Lab 1 to match the prototypes in the List header file. In other words:
        For EACH of these functions, you will need to template them.
       Also you *may* need to change the type of data that they return or take in as a parameter so that it is generic.
Here is an example of how to alter one of these functions:
template<class listdata>
void List<listdata>::insertStart(listdata data) {
    if (size == 0) { 
        start = stop = new Node(data);
    } else {
        Node* N = new Node(data);
        N->linknext = start;
        start = N;
    }
    size++;
}
Step 4: Now, build your List.cpp file and correct any errors that the compiler is giving you.
Step 5: Inside of ListTest.cpp, alter any calls to your List constructor to specify that the list contains ints, by placing the word int inside of the <>. Please see below: 
int main()
{
    List<int> L1; //indicate the list holds ints
    L1.insertStart(0);

    List<string> L2; //indicate the list holds strings

    L2.insertStart("hi");

}

Now, compile and run your code and verify that it works identically to the previous version without templates
Step 6: When you compile and run your code now (with your main function inside of ListTest.cpp), your code WILL NOT work.
To solve this problem, you must cut and paste all of the code from your List.cpp and place it inside your List.h file. This code will go at the very bottom, outside of and below the List class definition. 
I want your List.h to look like this:
class List {

    //private fields

   //public function prototypes

    //No function definitions in here!!

};

//copy and paste all of the functions from List.cpp here

//Note that libraries and namespace should go at the top of this file, not right here


Now, you should have only two functional files: List.h and ListTest.cpp
You can leave List.cpp as an empty file or simply comment out the contents of this file.
Step 7: Compile and run your code again and verify that it is now working.
Once you are sure it is still working properly, try testing your list with different types of data. 
For example, make Lists of strings, doubles, chars.

Part 2: Creating a Doubly-Linked List 
The next part of the assignment is to alter the list that you wrote in class and lab to be a doubly-linked list. 
The principle difference between the singly-linked list that you wrote in class and a doubly-linked list is that each node contains a pointer both to the next node and to the previous node in the list.
You can visualize a doubly-linked list likes so:


Image source.

Therefore, your inner Node struct will look like the following:

               struct Node {

        listdata data;
        Node* linknext;
        Node* linkprevious;
        Node(listdata newData) {
                data = newData;
                linknext = NULL;
                linkprevious = NULL; 
        }

       };

Additionally, bear in mind that the start Node of the list now has a linkprevious Node pointer to NULL while the stop Node has a linknext Node pointer to NULL.
The advantage of the previousnode pointer is the ease with which we can traverse the list in both directions.
To account for the presence of this additional pointer, you will need to make updates to your code for many of the list operations.
Most of these updates are as simple as adding one line of code per function.
For example, let's look at the insertStart operation:
template<class listdata>
void List<listdata>::insertStart(listdata data) {
    if (size == 0) { 
        start = stop = new Node(data);
    } else {
        Node* N = new Node(data);
        N->linknext = start;
        start->linkprevious = N;
        start = N;
    }
    size++;
}
Important! Each time you update one of your functions, run your tests again to make sure your list is still working properly.

More Information
If you want more information on doubly-linked lists, you can watch this short video (4.5 min).


Part 3: Adding New Functions to your List

Your doubly-linked list needs to be able to perform all of the same operations as your singly linked list. 
In addition, you must add some additional functions to your List class. 
All of the required functions are described below:


Constructors:

constructor: constructs a new linked list object.
copy constructor: makes a copy of the list object
destructor: frees the memory associated with the linked list

Manipulation Procedures:

removeStart: removes the element at the beginning of the list    
removeStop: removes the element at the end of the list
insertStart: inserts an element at the beginning of the linked list
insertStop: inserts an element at the end of the list
pointIterator: moves the iterator to the start of the list
deleteIterator: removes the element currently pointed to by the iterator. Iterator then points to NULL.
insertIterator: inserts an element after the node currently pointed to by the iterator
advanceIterator: moves the iterator up by one node towards stop
reverseIterator: moves the iterator down by one node towards start

Access Functions:

getStart: returns the data of the first element
getStop: returns the data of the last element
isEmpty: tests whether the linked list is empty
getSize: returns the current size of the list
getIterator: returns the element currently pointed at by the iterator
offEnd: returns whether the iterator is off the end of the list, i.e. is NULL
==: compares this list to see if it contains the same data, in the same order as another list.


Additional Operations:

print: prints the contents of the linked list to the screen separated by a blank space
printNumberedList: prints the contents of the linked list to the screen in the format #: <element> followed by a newline



Part 4: Handling Preconditions
Make sure that you are handling ALL preconditions using assert in your List class, as described in class.
Update your functions as necessary to use assert for these preconditions.
See Lesson 3 for more information and examples.


Part 5: Anagrams
Create a file called Anagram.cpp, which takes in a user input of a word.
The user will have the option to swap letters within that word.
You are required to use your templated doubly-linked list class to receive credit for this part of the assignment.
Therefore, your word should be stored in the List of chars.
The program should welcome the user and prompt the user for a word
It should then print out each character with its position number.
The user will then be prompted in enter the position of two different letters in the word that the user wants to be swapped.
The program will verify the user choice by re-printing the word with carrots beneath the selected letters.
If the user indicates "no", the word will be reprinted with a prompt to enter the position of two more letters, like so:
Welcome to the Anagram Arranger!

Please enter a word: zombie
1: z
2: o
3: m
4: b
5: i
6: e

Enter the position numbers of the two letters you wish to swap: 3 4

z o m b i e 
    ^ ^       
Are these the letters you wish to swap? (y/n): n

1: z
2: o
3: m
4: b
5: i
6: e

Enter the position numbers of the two letters you wish to swap: etc...

The program should proceed to swap the two letters given any of the following inputs: yes, Yes, y, or Y
Once the two letters are swapped, ask the user whether they wish to swap two more letters.
If the user does not type yes, Yes, y, or Y, end the program by printing "Bye!" to the console.
Anagram.cpp should give identical output to the output below (given the same user input):
Example 1:

Welcome to the Anagram Arranger!

Please enter a word: spells
1: s
2: p
3: e
4: l
5: l
6: s

Enter the position numbers of the two letters you wish to swap: 2 5

s p e l l s 
  ^     ^         
Are these the letters you wish to swap? (y/n): yes

The new word is: s l e l p s 

Want to keep rearranging? (y/n): Y

1: s
2: l
3: e
4: l
5: p
6: s

Enter the position numbers of the two letters you wish to swap: 1 4

s l e l p s 
^     ^       
Are these the letters you wish to swap? (y/n): Yes

The new word is: l l e s p s 

Want to keep rearranging? (y/n): yes

1: l
2: l
3: e
4: s
5: p
6: s

Enter the position numbers of the two letters you wish to swap: 1 2

l l e s p s 
^ ^   
Are these the letters you wish to swap? (y/n): y

The new word is: l l e s p s 

Want to keep rearranging? (y/n): n

Bye!

Your Anagram.cpp should also do error checking for the following cases only:
The user inputs a position number that is higher than the position of the last character in the word
The user reverses the order of the two positions by giving the higher number followed by the lower number
The user enters the same position number twice.
No other error checking is required.
Please see example below for how to handle this error checking:

Example 2:

Welcome to the Anagram Arranger!

Please enter a word: pumpkin
1: p
2: u
3: m
4: p
5: k
6: i
7: n

Enter the position numbers of the two letters you wish to swap: 2 40

Invalid entry!

1: p
2: u
3: m
4: p
5: k
6: i
7: n

Enter the position numbers of the two letters you wish to swap: 40 2

Invalid entry!

1: p
2: u
3: m
4: p
5: k
6: i
7: n

Enter the position numbers of the two letters you wish to swap: 3 2

Invalid entry!

1: p
2: u
3: m
4: p
5: k
6: i
7: n

Enter the position numbers of the two letters you wish to swap: 1 1

Invalid entry!

1: p
2: u
3: m
4: p
5: k
6: i
7: n

Enter the position numbers of the two letters you wish to swap: 1 3

p u m p k i n 
^   ^     
Are these the letters you wish to swap? (y/n): y

The new word is: m u p p k i n 

Want to keep rearranging? (y/n): n

Bye!


Specifications for Submission
Please submit 3 files to Canvas by the Tuesday deadline:
List.h (header file as created in class - now with ALL of your full function definitions as described above)
ListTest.cpp (test file with multiple tests for each function you write - this should be the test file you write, not the one I provide you. Please copy and paste the results of running your tests into the comments at the bottom of the file)
Anagram.cpp (source file with all of the logic to process words identically to what is shown above)
Important: You must name your files exactly as described above -- List.h, ListTest.cpp and Anagram.cpp -- for full credit
Also, your code must compile using gcc on Eclipse for C++.
You must use NULL, not nullptr
Please do not submit as a Zip file


How You Will Be Graded:

No credit if your List.h file does not contain the functions specified in the directions or if the Node struct has been altered in any way from what was given in class.
Also, you are not permitted to add any additional List functions to those specified or you will receive no credit for this assignment.
Make sure that you test your list thoroughly inside of ListTest.cpp!
No credit if your assignment doesn't compile or run using the Eclipse IDE as specified above
No credit if your program doesn't compile. Make sure to comment out the parts that aren't working (if any) before you submit.
No credit for Anagram.cpp if you do not use the templated doubly-linked List class defined in parts 1-4 of this Lab to complete the Anagram.cpp program by storing each word in a List of chars and manipulating the word using the List operations you wrote.
Please include a block comment with your name on the top of EACH file like so:
/**

* FirstName LastName

* CIS 22C, Lab 2

*/

70% of the credit will be for submitting a complete and functional templated, doubly-linked list, with your own test file
30% of the credit will be for a fully functional Anagram.cpp as demonstrated using the examples above
Sign in|Recent Site Activity|Report Abuse|Print Page|Powered By Google Sites
