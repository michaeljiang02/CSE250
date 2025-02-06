/****************************************************************************\
 * LinkedList.h
 *
 *  Created on:
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: ?
 *  \\TODO
 *  You can add your implementation details here or in the header,
 *  or with appropriate variable's or function's comments.
 *
 \***************************************************************************/

#include "LinkedList.h"

#include <iostream>
using namespace std;


/** Constructs an empty list.  */
LinkedList::LinkedList() {
    //TODO
};

/** Deletes an empty list by freeing nodes memory. */
LinkedList::~LinkedList() {
	while (Length() > 0) {
		RemoveFirst();
	}
}

/** Returns the length of the list in O(1).
 * Return: Length of the list
 */
int LinkedList::Length() {
    //TODO
	return 0;
}

/** Prints all the element of the list using cout, on a single line, separated by a comma. eg: [3, 19, 2, 36].*/
void LinkedList::PrintList() {
    if (m_First != nullptr) {
        //TODO

    } else {
        cout << "[]" << endl;
    }
}

/** Inserts a new string in first position in O(1).
 * Args: new_value is the new string to put in the list
 */
void LinkedList::InsertFirst(const string &new_value){
	//TODO
}


/** Removes and returns the first element of the list in O(1).
 * Return: The string removed, or "" if empty
 */
string LinkedList::RemoveFirst() {
	if (m_First != nullptr) {
		string ret = m_First->value;
		Node* todel = m_First;
		//TODO
		delete todel;
		return ret;
	} else {
		return string("");
	}
}

/** Returns the string at a given index (1st node at index 0, 2nd at index 1, etc...) in O(n).
 *  Args: index node position =  1st node at index 0, 2nd at index 1, etc...
 *  Return: "" if the index does not exists */
string LinkedList::GetValueAt(int index) {
	//TODO
	return "";
}


