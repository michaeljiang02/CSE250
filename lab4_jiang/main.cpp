/****************************************************************************\
* main.cpp
*
*  Created on: 2025
*      Author: YOUR NAME
 *
*
*  TODO: Make sure to demonstrate the appropriate functionality of your
*  binary search tree by testing ALL the cases in provided documents.
*  Your output must be EXPLICIT about what is tested and what is the result.
*
\***************************************************************************/

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
	cout << "CSE250 - Lab4 " << endl;


	//Example
	BST* tree = new BST();
	tree->insert(38, "Data38");

	tree->insert(15, "Data15");
	tree->insert(42, "Data42");
	tree->insert(17, "Data17");
	tree->insert(39, "Data39");
    string data = tree->remove(38);
    cout << data;

	cout << "Printing the complete tree in order" << endl;
	tree->inOrder();
    tree->printTree();
    cout << tree->search(39) << endl;
    cout << tree->height() << endl;

//	string retrievedData = tree->remove(39);
//	cout << "Deleting key " << 39 << " with data " << retrievedData << endl;
//	cout << "Printing the complete tree in order" << endl;
//	tree->printTree();


	return 0;
}
