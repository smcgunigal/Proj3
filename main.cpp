//
//  main.cpp
//  Proj3
//
//  Created by Sean McGunigal on 3/13/15.
//  Copyright (c) 2015 Sean McGunigal. All rights reserved.
//

#include <iostream>
#include <string>

//#include "ArrayClass.h" //or YOUR OWN VECTOR CLASS

using namespace std;

// your code for ArrayLinkedList class
#define MAX_SIZE 100

// Exception classes as given in the project description
class LinkedListException: public exception{};
class LinkedListMemory: public LinkedListException{};
class LinkedListBounds: public LinkedListException{};
class LinkedListNotFound: public LinkedListException{};

/************************************************
 * ArrayClass(): Written by Sean McGunigal      *
 *                                              *
 *  This class is used to store the data in the *
 *  LinkedListRow class. It essentially         *
 *  functions like a normal array.              *
 ************************************************/

template<class DT>
class ArrayClass {
private:
    DT* _data; // an array of data
    int _size;  // the size of the array
    int _maxSize;  // the largest size _data can be.
public:
    // constructors, including a copy constructor
    ArrayClass<DT>();
    ArrayClass<DT>(int maxSize);
    ArrayClass<DT>(int maxSize, DT value);
    ArrayClass<DT>(ArrayClass<DT>& copyThis);
    // destructor
    ~ArrayClass();
    // getters
    DT* getData();
    int getSize();
    int getMaxSize();
    // add an element to the end of the array
    void add(DT& data);
    // insert the element in the array
    void insert(DT& data, int index);
    // find an element in the array.
    int find(DT data);
    // remove an element in the array
    void remove(DT data);
    // remove the element at a given index
    void removeIndex(int index);
    // operator to access _data
    DT& operator [] (int i);
};

// No arg constructor with the default set to 100
template<class DT>
ArrayClass<DT>::ArrayClass() {
    _data = new DT[100];
    _size = 0;
    _maxSize = 0;
}

// Constructor with the max size
template<class DT>
ArrayClass<DT>::ArrayClass(int maxSize) {
    _data = new DT[maxSize];
    _size = 0;
    _maxSize = maxSize;
}

// Constructor with a max size and a value to instantiate each of the elements to
template<class DT>
ArrayClass<DT>::ArrayClass(int maxSize, DT value) {
    _data = new DT[maxSize];
    _size = maxSize;
    for (int i = 0; i < _size; i++)
        _data[i] = value;
}

// Copy constructor
template<class DT>
ArrayClass<DT>::ArrayClass(ArrayClass& copyThis) {
    _maxSize = copyThis.getMaxSize();
    _size = copyThis.getSize();
    _data = new DT[_maxSize];
    for (int i = 0; i < _size; i++)
        _data[i] = copyThis[i];
}

// Destructor
template<class DT>
ArrayClass<DT>::~ArrayClass() {
    delete [] _data;
}

// Getters
template<class DT>
DT* ArrayClass<DT>::getData() {
    return _data;
}

template<class DT>
int ArrayClass<DT>::getSize() {
    return _size;
}

template<class DT>
int ArrayClass<DT>::getMaxSize() {
    return _maxSize;
}

// Add an element to the end
template<class DT>
void ArrayClass<DT>::add(DT& data) {
    if (_size < _maxSize)
        _data[_size++] = data;
    else
        cout << "The array is full." << endl;
}

// Insert an element
template<class DT>
void ArrayClass<DT>::insert(DT& data, int index) {
    if (_size < _maxSize) {
        for (int i = _size; i > index; i--)
            _data[i] = _data[i-1];
        _data[index] = data;
        _size++;
    } else {
        cout << "The array is full." << endl;
    }
}

// Find an element and return the index, else return -1
template<class DT>
int ArrayClass<DT>::find(DT data) {
    for (int i = 0; i < _size; i++) {
        if (_data[i] == data)
            return i;
    }
    return -1;
}

// Remove an element
template<class DT>
void ArrayClass<DT>::remove(DT data) {
    for (int i = 0; i < _size; i++) {
        if (_data[i] == data) {
            for (int j = i; j < _size-1; j++)
                _data[j] = _data[j+1];
            _size--;
        }
    }
}

// Remove an element with a given index
template<class DT>
void ArrayClass<DT>::removeIndex(int index) {
    for (int i = index; i < _size-1; i++)
        _data[i] = _data[i+1];
    _size--;
}

// Overloaded [] operator
template<class DT>
DT& ArrayClass<DT>::operator[](int i) {
    return _data[i];
}

/************************************************
 * ArrayLinkedListRow(): Given in the project   *
 *  Description                                 *
 *                                              *
 *  This class was given in the Project 3       *
 * description. I added all the methods after   *
 * the = operator.                              *
 ************************************************/

template<class DT>
class ArrayLinkedListRow
{
private:
    DT* _info; // store data
    int _next; // next node
    int _nextEmpty; // next empty slot
public:
    ArrayLinkedListRow();
    // add other constructors that you need
    ArrayLinkedListRow( int nextEmpty);
    ~ArrayLinkedListRow();
    template<class T> friend ostream& operator<<(ostream& s,
                                                 ArrayLinkedListRow<T>& r);
    
    void operator=(const ArrayLinkedListRow<DT>& r);
    // add getters, setters or other methods and other methods
    // necessary for this class
    
    // Getters
    DT* getInfo();
    int getNext();
    int getNextEmpty();
    // Setters
    void setNextEmpty(int i);
    void setInfo(DT& info);
    void setNext(int i);
};

// No arg constructor
template<class DT>
ArrayLinkedListRow<DT>::ArrayLinkedListRow() {
    _info = new DT;
    _next = -2;
    _nextEmpty = 0;
}

// Destructor
template<class DT>
ArrayLinkedListRow<DT>::~ArrayLinkedListRow<DT>() {
    delete _info;
}

// Constructor with nextEmpty
template<class DT>
ArrayLinkedListRow<DT>::ArrayLinkedListRow(int nextEmpty) {
    _info = new DT;
    _nextEmpty = nextEmpty;
    _next = 0;
}

// Setters
template<class DT>
void ArrayLinkedListRow<DT>::setNextEmpty(int i) {
    _nextEmpty = i;
}

template<class DT>
void ArrayLinkedListRow<DT>::setInfo(DT& info) {
    (*_info) = info;
}

template<class DT>
void ArrayLinkedListRow<DT>::setNext(int i) {
    _next = i;
}

// Getters
template<class DT>
int ArrayLinkedListRow<DT>::getNext() {
    return _next;
}

template<class DT>
int ArrayLinkedListRow<DT>::getNextEmpty() {
    return _nextEmpty;
}

template<class DT>
DT* ArrayLinkedListRow<DT>::getInfo() {
    return _info;
}

/************************************************
 * ArrayLinkedList(): Given in the project      *
 *  Description                                 *
 *                                              *
 *  This class was given in the Project 3       *
 * description. I added all the _capacity field *
 * and the getters.                             *
 ************************************************/

template<class DT>
class ArrayLinkedList
{
private:
    //DT* _info[MAX_SIZE];  // store data
    //int _next[MAX_SIZE];   // next node
    //int _nextEmpty[MAX_SIZE];  // next empty slot
    
    ArrayClass< ArrayLinkedListRow<DT> >* _rows;
    
    int _head;   // head of the list
    int _firstEmpty;   // first empty slot
    int _size;
    void copy(const ArrayLinkedList<DT>& ll);//copy from another list
    // add a new node with next as it's next node and returns the index of new node
    int newNode( DT& newObject, int next);
    int _capacity; // The maximum size of the linked list.
public:
    ArrayLinkedList();    // empty and copy constructors
    ArrayLinkedList(ArrayLinkedList<DT>& ll);
    // Constructor that create a list with newObject as the head
    ArrayLinkedList(DT& newObject);
    
    // Constructor with a given capacity
    ArrayLinkedList(int capacity);
    
    // Constructor with newObject as the head and capacity
    ArrayLinkedList(DT& newObject ,int capacity);
    
    ~ArrayLinkedList();   // destructor
    
    bool isEmpty();
    // is the list empty?
    int size() const;  // return the number of nodes stored
    
    void add(DT& newObject); // add an object to the tail
    
    // insert an object at the position specified
    void insertAt(DT& newObject, int position);
    
    DT remove(); // remove the head
    // remove an object at the position specified
    DT removeAt(int position);
    
    // find the object that matches key, index of the object
    int find(DT key);
    
    // = operator
    void operator=(const ArrayLinkedList<DT>& ll);
    
    // overloading [] operator, return a reference to object at the
    // position in the linked list
    DT& operator[] (const int position);
    
    // ostream operator
    template<class T> friend ostream& operator<<(ostream& s,
                                                 ArrayLinkedList<T>& ll);
    // display raw data of the data members
    void displayRaw();
    
    ArrayClass< ArrayLinkedListRow<DT> >* getRows() const;
    int getHead() const;
    int getFirstEmpty() const;
};

// implement the methods here

// Copy method, used in the copy constructor
template<class DT>
void ArrayLinkedList<DT>::copy(const ArrayLinkedList<DT>& ll) {
    _head = ll.getHead();
    _firstEmpty = ll.getFirstEmpty();
    _size = ll.size();
    
    // Copy the array exactly
    for (int i = 0; i < ll.getRows()->getMaxSize(); i++) {
        (*_rows)[i].setInfo((*((*ll.getRows())[i].getInfo())));
        (*_rows)[i].setNext((*ll.getRows())[i].getNext());
        (*_rows)[i].setNextEmpty((*ll.getRows())[i].getNextEmpty());
    }
}

// Method to create a new node, which returns the index of the node.
template<class DT>
int ArrayLinkedList<DT>::newNode(DT &newObject, int next) {
    int returnVal = -1;
    if (_size == _capacity || _firstEmpty < 0) {
        throw LinkedListMemory();
    } else {
        (*_rows)[_firstEmpty].setInfo(newObject);
        (*_rows)[_firstEmpty].setNext(next);
        int tempEmpty = (*_rows)[_firstEmpty].getNextEmpty();
        (*_rows)[_firstEmpty].setNextEmpty(-2);
        returnVal = _firstEmpty;
        _firstEmpty = tempEmpty;
        _size++;
    }
    return returnVal;
}

// No arg constructor, sets the capacity to the MAX_SIZE
template<class DT>
ArrayLinkedList<DT>::ArrayLinkedList() {
    _rows = new ArrayClass<ArrayLinkedListRow<DT> >(MAX_SIZE);
    _head = -1;
    _firstEmpty = 0;
    _size = 0;
    _capacity = MAX_SIZE;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        (*_rows)[i].setNextEmpty(i+1);
        (*_rows)[i].setNext(-2);
    }
    (*_rows)[MAX_SIZE-1].setNextEmpty(-1);
}

// Constructor which adds an object
template<class DT>
ArrayLinkedList<DT>::ArrayLinkedList(DT& newObject) {
    _rows = new ArrayClass<ArrayLinkedListRow<DT> >(MAX_SIZE);
    _head = 0;
    _firstEmpty = 1;
    _size = 1;
    _capacity = MAX_SIZE;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        (*_rows)[i].setNextEmpty(i+1);
        (*_rows)[i].setNext(-2);
    }
    (*_rows)[MAX_SIZE-1].setNextEmpty(-1);
    
    // Add the new object
    (*_rows)[0].setInfo(newObject);
    (*_rows)[0].setNext(-1);
    (*_rows)[0].setNextEmpty(-2);
    
}

// Copy constructor
template<class DT>
ArrayLinkedList<DT>::ArrayLinkedList(ArrayLinkedList<DT>& ll) {
    _rows = new ArrayClass<ArrayLinkedListRow<DT> >(MAX_SIZE);
    
    copy(ll);
}

// Constructor with a capacity
template<class DT>
ArrayLinkedList<DT>::ArrayLinkedList(int capacity) {
    _rows = new ArrayClass<ArrayLinkedListRow<DT> >(capacity);
    _head = -1;
    _firstEmpty = 0;
    _size = 0;
    _capacity = capacity;
    
    for (int i = 0; i < capacity; i++) {
        (*_rows)[i].setNextEmpty(i+1);
        (*_rows)[i].setNext(-2);
        (*_rows)[i].setInfo(NULL);
    }
    (*_rows)[capacity-1].setNextEmpty(-1);}

// Constructor with a new object and a capacity
template<class DT>
ArrayLinkedList<DT>::ArrayLinkedList(DT& newObject, int capacity) {
    _rows = new ArrayClass<ArrayLinkedListRow<DT> >(capacity);
    _head = 0;
    _firstEmpty = 1;
    _size = 1;
    _capacity = capacity;
    
    for (int i = 0; i < capacity; i++) {
        (*_rows)[i].setNextEmpty(i+1);
        (*_rows)[i].setNext(-2);
        (*_rows)[i].setInfo(NULL);
    }
    (*_rows)[capacity-1].setNextEmpty(-1);
    
    // Add the new object
    (*_rows)[0].setInfo(newObject);
    (*_rows)[0].setNext(-1);
    (*_rows)[0].setNextEmpty(-2);
    
}

// Destructor
template<class DT>
ArrayLinkedList<DT>::~ArrayLinkedList() {
    delete _rows;
}

// Method to test if the linked list is empty
template<class DT>
bool ArrayLinkedList<DT>::isEmpty() {
    if (_size == 0)
        return true;
    else
        return false;
}

// Getter for the size
template<class DT>
int ArrayLinkedList<DT>::size() const {
    return _size;
}

// Method to add an object to the head.
template<class DT>
void ArrayLinkedList<DT>::add(DT& newObject) {
    // If the array is empty, then the head becomes
    // the new node and the new node points to -1
    // which is the end.
    if (isEmpty()) {
        _head = newNode(newObject, -1);
    } else {
        // The while loop finds the tail of the list and
        // sets the tail's next to the index of the new
        // node.
        int tail = _head;
        while (((*_rows)[tail]).getNext() != -1)
            tail = (*_rows)[tail].getNext();
        ((*_rows)[tail]).setNext(newNode(newObject, -1));
    }
}

// Method to insert an element
template<class DT>
void ArrayLinkedList<DT>::insertAt(DT &newObject, int position) {
    // Throw the exception as requested
    if (position < 0 || position > _size)
        throw LinkedListBounds();
    
    // If the position is 0, just make it the new head
    // and point it to the old head.
    if (position == 0) {
        _head = newNode(newObject, _head);
    } else {
        // Otherwise iterate the the right index, point the new node to
        // the old node's next node and point the old node to the new node.
        int i = _head;
        for (int j = 0; j < position-1; j++)
            i = (*_rows)[i].getNext();
        int tempNext = (*_rows)[i].getNext();
        (*_rows)[i].setNext(newNode(newObject, tempNext));
    }
}

// Remove the head of the linked list
template<class DT>
DT ArrayLinkedList<DT>::remove() {
    // Throw the exception as requested
    if (isEmpty())
        throw LinkedListBounds();
    
    // Move the head one up the list, clear the elements of the array
    // and add the deleted element to the head of the empty list.
    DT returnVal;
    int i = _head;
    _head = ((*_rows)[i]).getNext();
    returnVal = (*((*_rows)[i]).getInfo());
    ((*_rows)[i]).setNext(-2);
    ((*_rows)[i]).setNextEmpty(_firstEmpty);
    _firstEmpty = i;
    _size--;
    
    return returnVal;
}

// Remove the element at a given position
template<class DT>
DT ArrayLinkedList<DT>::removeAt(int position) {
    // Throw the exception as requested
    if (isEmpty() || position > (_size-1))
        throw LinkedListBounds();
    
    // If removing the head, call remove()
    if (position == 0)
        return remove();
    
    // Find the position
    DT returnVal;
    // i saves the index of the item before the element to be deleted.
    int i = _head;
    for (int j = 0; j < position-1; j++)
        i = (*_rows)[i].getNext();
    // DeleteMe is the index of the item to be deleted
    int deleteMe = (*_rows)[i].getNext();
    // K saves the index of the item after deleteMe
    int k = (*_rows)[deleteMe].getNext();
    // Point the element before to the element after
    ((*_rows)[i]).setNext(k);
    
    // Return the info in the deleted element, clear the element and add
    // it to the empty list
    returnVal = (*(*_rows)[deleteMe].getInfo());
    ((*_rows)[deleteMe]).setNext(-2);
    ((*_rows)[deleteMe]).setNextEmpty(_firstEmpty);
    _firstEmpty = deleteMe;
    _size--;
    
    return returnVal;
}

// Find an element in the list.
template<class DT>
int ArrayLinkedList<DT>::find(DT key) {
    int current = _head;
    // Iterate through the list, not the array
    for (int i = 0; i < _size; i++) {
        if ((*((*_rows)[current]).getInfo()) == key)
            return current;
        else
            current = (*_rows)[current].getNext();
    }
    // If the item isn't found, throw the exception
    throw LinkedListNotFound();
    // This shouldn't happen in our program, but I needed a return.
    return -1;
}

// The overloaded = operator, which calls the copy method
template<class DT>
void ArrayLinkedList<DT>::operator=(const ArrayLinkedList<DT> &ll) {
    copy(ll);
}

// Return the info at a given position in the list.
template<class DT>
DT& ArrayLinkedList<DT>::operator[] (const int position) {
    // If the head's info, return.
    if (position == 0)
        return (*(*_rows)[_head].getInfo());
    
    // If out of bounds, throw exception
    if (position >= _size || position < 0)
        throw LinkedListBounds();
    
    // Iterate to the element using a for loop, then return
    int index = _head;
    for (int i = 0; i < position; i++)
        index = (*_rows)[index].getNext();
    return (*(*_rows)[index].getInfo());
}

// Overloaded << operator, as described in the project description.
template<class T>
ostream& operator<<(ostream& s, ArrayLinkedList<T>& ll) {
    int current = ll.getHead();
    // Iterate through the list
    if (current == -1)
        return s;
    s << (*(*ll.getRows())[current].getInfo()) << '(' << current << ')';
    while ((*ll.getRows())[current].getNext() != -1) {
        current = (*ll.getRows())[current].getNext();
        s << " --> ";
        s << (*(*ll.getRows())[current].getInfo()) << '(' << current << ')';
    }
    s << endl;
    return s;
}

// DisplayRaw method, as detailed in the project description
template<class DT>
void ArrayLinkedList<DT>::displayRaw() {
    cout << "Head: " << _head << endl;
    cout << "First Empty: " << _firstEmpty << endl;
    cout << "Size: " << _size << endl;
    cout << "info: ";
    
    // The output for the next bit is messy because the capacity for the
    // classes used in the main method are large. The project description
    // was very clear about how much data to show in the array, so I
    // showed everything.
    for (int i = 0; i < _capacity; i++) {
        if ((*_rows)[i].getNext() != -2)
            cout << (*(*_rows)[i].getInfo()) << " ";
        else
            cout << "X ";
    }
    cout << endl;
    cout << "next: ";
    for (int i = 0; i < _capacity; i++)
        cout << (*_rows)[i].getNext() << " ";
    cout << endl;
    cout << "nextEmpty: ";
    for (int i = 0; i < _capacity; i++)
        cout << (*_rows)[i].getNextEmpty() << " ";
    cout << endl;
}

// Getters
template<class DT>
ArrayClass<ArrayLinkedListRow<DT> >* ArrayLinkedList<DT>::getRows() const {
    return _rows;
}

template<class DT>
int ArrayLinkedList<DT>::getHead() const {
    return _head;
}

template<class DT>
int ArrayLinkedList<DT>::getFirstEmpty() const {
    return _firstEmpty;
}

// Main class, as provided.
int main()
{
    
    ArrayClass<int> ai(5, 5);
    
    
    int i;
    int intData[100];
    
    for( i=0; i< 100; i++)
        intData[i] = i;
    
    // string data
    string zero("zero");
    string one("One");
    string two = "Two";
    string three = "Three";
    string four = "Four";
    string five = "Five";
    string six = "Six";
    string seven = "Seven";
    string eight = "Eight";
    string nine = "Night";
    string ten = "Ten";
    
    // ========================================================
    
    
    ArrayLinkedList<int> myIntList;
    ArrayLinkedList<string>* pMyStringList;
    
    
    cout << endl << "== Basic Operations ============================================================" << endl << endl;
    
    
    cout << "The size of myIntList is: " << myIntList.size() << endl;
    
    
    
    if( myIntList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;
    
    // test add method
    
    cout << endl << "================================================================================" << endl << endl;
    
    cout << "Adding objects to the list:";
    for( i=10; i> 0; i--)
    {
        myIntList.add( intData[i+10]);
        cout << " " << intData[i+10];
    }
    cout << endl;
    
    // test size method
    cout << "The size of myIntList is: " << myIntList.size() << endl;
    
    
    if( myIntList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;
    
    // test ostream<<
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    cout << endl << "================================================================================" << endl << endl;
    
    
    // test insertAt;
    // head
    cout << "Insert " << intData[0] << " to position " << 0 << endl;
    myIntList.insertAt( intData[0], 0);
    
    // tail
    int tail = myIntList.size();
    cout << "Insert " << intData[1] << " to position " << tail << endl;
    myIntList.insertAt( intData[1], tail);
    
    // somewhere in the middle
    cout << "Insert " << intData[50] << " to position " << tail/2 << endl;
    myIntList.insertAt( intData[50], tail/2);
    cout << myIntList << endl;
    
    
    
    // test copy constructor
    
    cout << endl << "================================================================================" << endl << endl;
    
    ArrayLinkedList<int> * pMyNewIntList;
    
    
    pMyNewIntList = new ArrayLinkedList<int>(myIntList);
    
    cout << "*pMyNewIntList (copied from muIntList)" << endl;
    cout << *pMyNewIntList << endl;
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    
    
    // test assignment operator
    
    cout << endl << "================================================================================" << endl << endl;
    
    
    pMyNewIntList->add( intData[51]); // add 51 to myIntList
    
    cout << "*pMyNewIntList" << endl;
    cout << *pMyNewIntList << endl;
    
    
    cout << "myIntList = *pMyNewIntList" << endl;
    
    myIntList = *pMyNewIntList;
    
    cout << "*pMyNewIntList" << endl;
    cout << *pMyNewIntList << endl;
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    
    cout << endl << "================================================================================" << endl << endl;
    
    
    
    // test remove
    
    cout << "Removing data from myIntList:";
    while( !myIntList.isEmpty())
        cout << " " << myIntList.remove();
    cout << endl;
    cout << "myIntList: (empty now)" << endl;
    cout << myIntList << endl;
    
    
    
    cout << "Copy from *pMyNewIntList" << endl;
    myIntList = *pMyNewIntList;
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    cout << endl << "================================================================================" << endl << endl;
    
    // test the destructor
    delete pMyNewIntList;
    pMyNewIntList = NULL;
    
    cout << "Removing the object at position 0, value: " <<  myIntList.removeAt(0) << endl; // head
    cout << "Removing the object at position 4, value: " <<  myIntList.removeAt(4) << endl; // 5th object
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    cout << "Adding an object with value 50 to the list, it will be at the position of last object removed in the array." << endl;
    myIntList.add( intData[50]);
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    cout << "Adding objects with value 51 and 23 to the list." << endl;
    myIntList.add( intData[51]);
    myIntList.add( intData[23]);
    
    cout << "myIntList:" << endl;
    cout << myIntList << endl;
    
    cout << endl << "================================================================================" << endl << endl;
    
    // test find
    cout << "Testing find() ..." << endl;
    cout << "The first object with value 51 is store at position " << myIntList.find(51) << " of the array." << endl;
    
    cout << "The first object with value 23 is store at position " << myIntList.find(23) << " of the array." << endl << endl;
    
    
    cout << "Testing operator[]..." << endl;
    for (i=0; i< myIntList.size(); i++) {
        cout << myIntList[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Replace the head with " << intData[80] << endl;
    
    myIntList[0] = intData[80];
    
    cout << "New list:" << endl;
    
    for (i=0; i< myIntList.size(); i++) {
        cout << myIntList[i] << " ";
    }
    cout << endl << endl;
    
    // call displayRaw()
    myIntList.displayRaw();
    
    
    // test exception handling
    
    cout << endl <<"== Exception Handling ==========================================================" << endl << endl;
    
    
    try{
        myIntList.removeAt(101);
    }
    catch (LinkedListBounds e)
    {
        cout << "Out of bounds." << endl;
    }
    
    try{
        myIntList.insertAt(intData[72], 50);
    }
    catch (LinkedListBounds e)
    {
        cout << "Out of bounds." << endl;
    }
    
    int size = myIntList.size();
    
    try{
        
        for( i=0; i< 101 - size; i++)
        {
            myIntList.add(intData[i]);
        }
    }
    catch (LinkedListMemory e)
    {
        cout << "List full ( i = " << i << ")." << endl;
    }
    
    
    try{
        myIntList.insertAt(intData[20], 30);
    }
    catch (LinkedListMemory e)
    {
        cout << "List full." << endl;
    }
    
    
    try{
        cout << myIntList[200] << endl;
    }
    catch (LinkedListBounds e)
    {
        cout << "Out of bounds." << endl;
    }
    
    cout << myIntList << endl;
    
    try{
        myIntList.find(500);
    }
    catch (LinkedListNotFound e)
    {
        cout << "500: Not found." << endl;
    }
    
    cout << endl << "== String ======================================================================" << endl << endl;
    
    // test the class on the string
    
    // test non default constructor
    pMyStringList = new ArrayLinkedList<string>(zero);
    
    cout << *pMyStringList << endl;
    
    // add
    pMyStringList->add(one);
    pMyStringList->add(three);
    pMyStringList->add(five);
    pMyStringList->add(six);
    pMyStringList->add(seven);
    pMyStringList->add(eight);
    pMyStringList->add(nine);
    pMyStringList->add(ten);
    
    cout << *pMyStringList << endl;
    
    // insertAt
    
    pMyStringList->insertAt( four, 3);
    pMyStringList->insertAt( two, 2);
    
    cout << *pMyStringList << endl;
    
    // remove
    pMyStringList->remove();
    cout << *pMyStringList << endl;
    
    // removeAt
    pMyStringList->removeAt(5);
    cout << *pMyStringList << endl;
    
    cout << seven << " is found at position " << pMyStringList->find(seven) <<endl;
    
    // =operator
    ArrayLinkedList<string> MyNewStringList;
    
    MyNewStringList = *pMyStringList;
    
    delete pMyStringList;
    
    pMyStringList = NULL;
    
    cout << MyNewStringList << endl;
    
    for (i=0; i< MyNewStringList.size(); i++) {
        cout << MyNewStringList[i] << " ";
    }
    cout << endl;
    
    cout << MyNewStringList << endl;
    
    
    MyNewStringList.displayRaw();
    
    
    return 0;
}