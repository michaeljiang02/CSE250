/****************************************************************************\
 * Stack.cpp
 *
 *  Created on: Feb 13 2023
 *      Author: Michael Jiang
 *
 *
 *  Implementation details:
 *  The implementation is very simple, I am using a linked list for my stack. There are not many edge cases
 *  because a linked list cannot be full. To push an item, we will simply call the InsertFirst() method and
 *  RemoveFirst() method to pop an item. The implementation of these methods are found in LinkedList.cpp.
 *
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
 *
 \***************************************************************************/

#include "Stack.h"

#include <iostream>
using namespace std;


/** Constructs an empty stack. */
Stack::Stack() {
    m_List = LinkedList();
}

/** Deletes the stack. */
Stack::~Stack(){
    while (m_List.Length() > 0) {
        m_List.RemoveFirst();
    }
}

/** Indicates whether the stack is empty in O(1).
 * Returns: true is empty, false if not
 */
bool Stack::IsEmpty() {
	return m_List.Length() == 0;
}

/** Prints all the element of the stack using cout, from top to bottom (1 item per line).
 *  WHAT IS THE O() OF YOUR METHOD? EXPLAIN IN YOUR REPORT (or via couts in the main)
 */
void Stack::PrintStack() {
    m_List.PrintList();
}

/** Adds a string on the top of the stack in O(1).
 * Args: New string to put on top of the stack.
 */
void Stack::Push(const string &new_value) {
	m_List.InsertFirst(new_value);
}

/** Removes and returns the string on the top of the stack in O(1).
 * Return: string on top of the stack or "" if empty.
 */
string Stack::Pop() {
	if (IsEmpty()) {
        return string(" ");
    }
    string value = m_List.RemoveFirst();
	return value;
}

/** Returns the string on the top of the stack in O(1).
 * Return: String on top of the stack or "" if empty.
 * */
string Stack::Top() {
    if (IsEmpty()) {
        return string(" ");
    }
	return m_List.GetValueAt(0);
}



