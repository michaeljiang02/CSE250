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


	cout << "---------------- Question 1 ----------------" << endl << endl;
	BST* t = new BST();
	cout << "t->preOrder() outputs "; t->preOrder();
	cout << "t->postOrder() outputs "; t->postOrder();
	cout << "t->inOrder() outputs "; t->inOrder();
	cout << "t->search(4) outputs " << t->search(4) << endl;
	cout << "t->printTree() outputs "; t->printTree();
	cout << "t->height() outputs "<< t->height() << endl;
	cout << "t->remove(4) outputs " << t->remove(4) << endl << endl;
	delete t;

	cout << "---------------- Question 2 ----------------" << endl << endl;
	BST* t2 = new BST();
	t2->remove(5);
	t2->insert(5, "Data5");
	t2->remove(5);
	t2->insert(10, "Data10");

	cout << "t->preOrder() outputs "; t2->preOrder();
	cout << "t->postOrder() outputs "; t2->postOrder();
	cout << "t->inOrder() outputs "; t2->inOrder();
	cout << "t->search(4) outputs " << t2->search(4) << endl;
	cout << "t->search(5) outputs " << t2->search(5) << endl;
	cout << "t->search(10) outputs " << t2->search(10) << endl;
	cout << "t->printTree() outputs "; t2->printTree();
	cout << "t->height() outputs "<< t2->height() << endl;
	cout << "t->remove(10) outputs " << t2->remove(10) << endl << endl;
	delete t2;

	cout << "---------------- Question 3 ----------------" << endl << endl;
	BST* t3 = new BST();
	t3->insert(10, "Data10");
	t3->insert(5, "Data5");
	t3->insert(15, "Data15");
	t3->insert(6, "Data6");
	t3->insert(3, "Data3");
	t3->insert(16, "Data16");
	t3->insert(13, "Data13");
	t3->insert(2, "Data2");
	t3->remove(5);

	cout << "t->preOrder() outputs "; t3->preOrder();
	cout << "t->postOrder() outputs "; t3->postOrder();
	cout << "t->inOrder() outputs "; t3->inOrder();
	cout << "t->search(13) outputs " << t3->search(13) << endl;
	cout << "t->search(100) outputs " << t3->search(100) << endl;
	cout << "t->search(5) outputs " << t3->search(5) << endl;
	cout << "t->printTree() outputs "; t3->printTree();
	cout << "t->height() outputs "<< t3->height() << endl;

	cout << "---------------- Question 4 ----------------" << endl << endl;
	BST* t4 = new BST();
	t4->insert(15, "Data15");
	t4->insert(14, "Data14");
	t4->insert(12, "Data12");
	t4->insert(13, "Data13");
	t4->insert(10, "Data10");
	t4->remove(13);

	cout << "t->preOrder() outputs "; t4->preOrder();
	cout << "t->postOrder() outputs "; t4->postOrder();
	cout << "t->inOrder() outputs "; t4->inOrder();
	cout << "t->search(13) outputs " << t4->search(12) << endl;
	cout << "t->search(100) outputs " << t4->search(10) << endl;
	cout << "t->search(5) outputs " << t4->search(13) << endl;
	cout << "t->printTree() outputs "; t4->printTree();
	cout << "t->height() outputs "<< t4->height() << endl;

	cout << "---------------- Question 5 ----------------" << endl << endl;
	BST* t5 = new BST();
	t5->insert(15, "Data15");
	t5->insert(16, "Data16");
	t5->insert(19, "Data19");
	t5->insert(17, "Data17");
	t5->insert(20, "Data20");
	t5->remove(19);
	t5->remove(15);

	cout << "t->preOrder() outputs "; t5->preOrder();
	cout << "t->postOrder() outputs "; t5->postOrder();
	cout << "t->inOrder() outputs "; t5->inOrder();
	cout << "t->search(15) outputs " << t5->search(15) << endl;
	cout << "t->search(20) outputs " << t5->search(20) << endl;
	// cout << "t->printTree() outputs "; t5->printTree();
	cout << "t->height() outputs "<< t5->height() << endl;

	return 0;


}
