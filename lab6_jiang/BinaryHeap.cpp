/*
 * BinaryHeap.cpp
 *
 * Michael Jiang
 *
 *      Author: Rivest, 2025
 */

#include "BinaryHeap.h"
#include <limits>
#include <string>
#include <sstream>

/** This constructs a heap for vertices from 0 to initialSize-1,
 *  with all keys at infinity.
 *
 * @param initialSize  	Number of vertices in the heap
 */
BinaryHeap::BinaryHeap(int initialSize) {
	heapValues = new double[initialSize];
	heap2Vertex = new int[initialSize];
	vertex2Heap = new int[initialSize];
	heapSize = initialSize;
	vertexCount = initialSize;
	//Initialize the heap structure with each vertex at the same position
	//as its number. Since everyone is at infinity, this is okay.
	for (int i=0; i<initialSize; i++) {
		heapValues[i] = std::numeric_limits<double>::max();
		heap2Vertex[i] = i;
		vertex2Heap[i] = i;
	}
}

/** Clean up heap memory */
BinaryHeap::~BinaryHeap() {
	delete[] heapValues;
	delete[] heap2Vertex;
	delete[] vertex2Heap;
}

/** Swaps 2 nodes and all the relevant information accordingly.
 *
 * @param index1	First heap index
 * @param index2	Second heap index
 */
void BinaryHeap::swap(int index1, int index2) {
	//Swap the heap information
	double tmpKey = heapValues[index1];
	int tmpVertex = heap2Vertex[index1];
	heapValues[index1] = heapValues[index2];
	heap2Vertex[index1] = heap2Vertex[index2];
	heapValues[index2] = tmpKey;
	heap2Vertex[index2] = tmpVertex;
	//Update the vertex to heap index array
	vertex2Heap[heap2Vertex[index1]] = index1;
	vertex2Heap[heap2Vertex[index2]] = index2;
}

/** This method extract the minimum value from the heap.
 * Fixes, the heap, and then return the vertex that was at the top.
 *
 * @return	The vertex at the top of the heap (the min key)
 */
int BinaryHeap::extractMin() {
	//Deal with error
	if (heapSize == 0) {
		throw ("Heap is empty");
	}
    //Here's the actual code
    int minVertex = heap2Vertex[0];
    swap(0, heapSize - 1);
    heapify(0);
    heapSize--;
    return minVertex;
}

/** This increases the key of a specific vertex
 *
 * @param vertex	vertex to update the key
 * @param newKey	new key value (must be smaller)
 */
void BinaryHeap::decreaseKey(int vertex, double newKey) {
	//Check if the vertex is a valid vertex
	if (vertex < 0 || vertex >= vertexCount) {
		std::ostringstream oss;
		oss << "Invalid vertex " << vertex;
		throw (oss.str());
	}
	//Check if that vertex is still in the heap
	if (vertex2Heap[vertex] == -1) {
		std::ostringstream oss;
		oss << "Vertex " << vertex << " not in heap";
		throw (oss.str());
	}
	//Check that the new key is smaller
	int heapIndex = vertex2Heap[vertex];
	if (newKey > heapValues[heapIndex]) {
		std::ostringstream oss;
		oss << "New key " << newKey << " is not smaller than the old key " << heapValues[heapIndex];
		throw (oss.str());
	}
	//Here's the actual code
	heapValues[heapIndex] = newKey;
	while (vertex != 0 && heapValues[heapIndex] < heapValues[parent(heapIndex)]) {
		swap(heapIndex, parent(heapIndex));
		heapIndex = parent(heapIndex);
	}
}

/** Fixes the heap assuming the key value at index is larger than it should
 *  I.e., it fixes the heap by moving the value at index downward
 *
 * @param index		Heap index to fix.
 */
void BinaryHeap::heapify(int index) {
    //Check if the index is a valid index
    if (index < 0 || index >= heapSize) {
        std::ostringstream oss;
        oss << "Invalid index " << index;
        throw (oss.str());
    }
    //Here's the actual code
    while ((heapValues[index] > heapValues[left(index)] && left(index) < heapSize) || (heapValues[index] > heapValues[right(index)] && right(index) < heapSize)) {
    	if (heapValues[left(index)] < heapValues[right(index)] && right(index) < heapSize) {
    		swap(left(index), index);
    		index = left(index);
    	} else {
    		swap(right(index), index);
    		index = right(index);
    	}
    }
}
