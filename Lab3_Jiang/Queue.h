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
		/** Max capacity of the circular buffer */
		int m_First;
		/** Index of the circular buffer before the first item of the queue. */
		int m_Last;
        /** Index of the circular buffer in which the next item will be queued.
         * IMPORTANT: This is not the index of the last item of the queue.
         */
		int length;
		/** Number of items currently inside the queue. */

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
		bool Dequeue(int &old_value);
};

#endif /* QUEUE_H_ */



