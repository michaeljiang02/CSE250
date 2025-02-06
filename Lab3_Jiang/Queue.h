/****************************************************************************\
 * Queue.h
 *
 *  Created on:
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: ?
 *
 \***************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

/** Queue of integers using an array. */
class Queue {

private:
		/** Array used as a circular buffer for queue content. */
		int* m_Data;
		/** Size of the circular buffer. */
		int m_MaxSize;
		/** TODO PLEASE DESCRIBE */
		int m_First;
		/** TODO PLEASE DESCRIBE */
		int m_Last;
        // TODO: Add other instance variables or helper methods if needed
		int length;

	public:
		/** Constructs an empty queue of maximum size new_max_size */
		Queue(int new_max_size);
		/** Deletes the queue and free up its memory. */
		virtual ~Queue();

		/** Indicates whether of not the queue is empty in O(1), true if empty, false if not. */
		bool IsEmpty();
        /** Indicates whether of not the queue is full in O(1), true if full, false if not. */
        bool IsFull();

		/** Prints the content of the queue on a single line, separated by comma, eg: [3, 19, 2, 36]. */
		void PrintQueue();

		/** Inserts an element at the end of the queue, returns true if succeed, and false if the queue is already full. */
		bool Enqueue(int new_value);
		/** Removes the element at the front of the queue and returns the element in the argument,
		 * returns true if succeed, and false if the queue is already full.  */
		bool Dequeue();
};

#endif /* QUEUE_H_ */



