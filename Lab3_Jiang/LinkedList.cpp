/****************************************************************************\
 * LinkedList.h
 *
 *  Created on: Feb 13 2023
 *      Author: Michael Jiang
 *
 *
 *  Implementation details:
 *
 *  This is a circular doubly linked list with a sentinel node. Some particular design choices are:
 *   - The first element of the list is always sentinel->next
 *   - The last element of the list is always sentinel->prev
 *   - An empty list has both pointers of the sentinel node pointing to the sentinel (itself).
 *   - We know that the list terminates when the sentinel node is reached.
 *   - Maintain a length attribute to track the number of nodes in the list.
 *
 \***************************************************************************/

#include "LinkedList.h"

#include <iostream>
using namespace std;


/** Constructs an empty list.  */
LinkedList::LinkedList() {
    sentinel = new Node();
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    length = 0;
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
    return length;
}

/** Prints all the element of the list using cout, on a single line, separated by a comma. eg: [3, 19, 2, 36].*/
void LinkedList::PrintList() {
    Node* walker = sentinel->next;
    if (walker == nullptr) {
        cout << "[]" << endl;
    }
    else {
        cout << "[";
        while (walker->next != sentinel) {
            cout << walker->value << ", ";
            walker = walker->next;
        }
        cout << walker->value << "]" << endl;
    }
}

/** Inserts a new string in first position in O(1).
 * Args: new_value is the new string to put in the list
 */
void LinkedList::InsertFirst(const string &new_value){
    Node* first = new Node();
    first->value = new_value;
    first->prev = sentinel;
    first->next = sentinel->next;
    sentinel->next->prev = first;
    sentinel->next = first;
    length++;
}


/** Removes and returns the first element of the list in O(1).
 * Return: The string removed, or "" if empty
 */
string LinkedList::RemoveFirst() {
    Node* m_First = sentinel->next;
	if (m_First != sentinel) {
		string ret = m_First->value;
		Node* todel = m_First;
		sentinel->next = m_First->next;
        m_First->next->prev = sentinel;
		delete todel;
        length--;
		return ret;
	} else {
		return string("");
	}
}

/** Returns the string at a given index (1st node at index 0, 2nd at index 1, etc...) in O(n).
 *  Args: index node position =  1st node at index 0, 2nd at index 1, etc...
 *  Return: "" if the index does not exists */
string LinkedList::GetValueAt(int index) {
    if (index >= length) {
        return string("");
    }
	Node* walker = sentinel->next;
    for (int i = 0; i < index; i++) {
        walker = walker->next;
    }
	return walker->value;
}


