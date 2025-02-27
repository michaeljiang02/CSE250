/****************************************************************************\
 * Queue.cpp
 *
 *  Created on: Feb 13 2025
 *      Author: Michael Jiang
 *
 *
 *  Implementation details:
 *
 *  This Queue data structure uses a circular array. Some particular design choices are:
 *   - The addition of the length attribute to track the number of elements in the queue.
 *   - Starting the m_Last attribute at -1 so that we do not need to implement an edge case when adding an element to an empty queue.
 *   - Using the length attribute to implement IsEmpty() and IsFull().
 *
 \***************************************************************************/
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(int new_max_size) {
    m_MaxSize = new_max_size;
    m_Data = new int[m_MaxSize];
    m_First = 0;
    m_Last = -1;
    length = 0;
}

/** Deletes the queue and free up its memory. */
Queue::~Queue() {
    delete[] m_Data;
}

bool Queue::IsEmpty() {
    return (length == 0);
}

bool Queue::IsFull() {
    return (length == m_MaxSize);
}

bool Queue::Enqueue(int new_value) {
    if (IsFull()) {
        return false;
    }
    m_Last = (m_Last + 1) % m_MaxSize;
    m_Data[m_Last] = new_value;
    length++;
    return true;
}

bool Queue::Dequeue(int &old_value) {
    if (IsEmpty()) {
        return false;
    }
    old_value = m_Data[m_First];
    m_First = (m_First + 1) % m_MaxSize;
    length--;
    return true;
}

void Queue::PrintQueue() {
    if (IsEmpty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    int current = (m_First) % m_MaxSize;
    for (int i = 0; i < length - 1; i++) {
        cout << m_Data[current] << ", ";
        current = (current + 1) % m_MaxSize;
    }
    cout << m_Data[current] << "]" << endl;
}
