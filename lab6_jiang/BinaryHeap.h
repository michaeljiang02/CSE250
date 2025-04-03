/*
 * BinaryHeap.h
 *
 * YOUR NAME HERE
 *
 *      Author: Rivest, 2025
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

/** Binary heap object
 *
 *  You need to implement your own heap for Dijkstra .
 *  The issue is that the network does not know the position of its
 *  vertices in the heap. Therefore, your heap has to keep track of them.
 *
 *  @author Your name here
 */
class BinaryHeap {
private:

	/** This is basically the heap values, as seen in class. */
	double* heapValues;
	/** This is containing for each position, the related vertex value. */
	int* heap2Vertex;
	/** This is containing for each vertex, its current position in the heap. */
	int* vertex2Heap;
	/** This is the current size of the heap, i.e. its valid content. */
	int heapSize;
	/** Total number of vertices in the graph (for vertex2Heap). */
	int vertexCount;


	//Put any extra network variables you want here

	/** Swaps 2 nodes and all the relevant information accordingly. */
	void swap(int index1, int index2);


	/** Fixes the heap assuming the key value at index is larger than it should. */
	void heapify(int index);

	/** Returns the index of the parent of a given index
	 *
	 * @param index		Node to find its parent
	 * @return			The index of the parent
	 */
	int parent(int index) {
		int p = (index-1)/2;
		return p;
	}


	/** Return the index of the left child of a given index
	 *
	 * @param index		Node to find its left child
	 * @return			The index of the left child
	 */
	int left(int index) {
		return 2*index+1;
	}


	/** Return the index of the right child of a given index
	 *
	 * @param index		Node to find its right child
	 * @return			The index of the right child
	 */
	int right(int index) {
		return 2*index+2;
	}

	//Put any extra private helper methods you want here



public:
	/** This constructs a heap for vertices from 0 to initialSize-1 */
	BinaryHeap(int initialSize);
	/** Clean up heap memory */
	virtual ~BinaryHeap();

	/** This method extract the minimum value from the heap. */
	int extractMin();
	/** This increases the key of a specific vertex. */
	void decreaseKey(int vertex, double newKey);

	/** Indicates whether the heap is empty
	 *
	 * @return  	true if the heap is empty
	 */
	int isEmpty () {
		return heapSize == 0;
	}
};

#endif /* BINARYHEAP_H_ */
