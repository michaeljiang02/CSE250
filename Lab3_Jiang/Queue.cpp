/****************************************************************************\
 * Queue.cpp
 *
 *  Created on:
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: ?
 *  \\TODO
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
 *
 \***************************************************************************/
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(int new_max_size) {
    m_MaxSize = new_max_size;
    m_Data = new int[m_MaxSize];
    m_First = 0;
    if (new_max_size == 1) {
        m_Last = 0;
    }
    else {
        m_Last = 1;
    }
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
    m_Data[m_Last] = new_value;
    m_Last = (m_Last + 1) % m_MaxSize;
    length++;
    return true;
}

bool Queue::Dequeue(int &old_value) {
    if (IsEmpty()) {
        return false;
    }
    old_value = m_Data[(m_First + 1) % m_MaxSize];
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
    int current = (m_First + 1) % m_MaxSize;
    for (int i = 0; i < length - 1; i++) {
        cout << m_Data[current] << ", ";
        current = (current + 1) % m_MaxSize;
    }
    cout << m_Data[current] << "]" << endl;
}




//TODO follow the templates of the other files



