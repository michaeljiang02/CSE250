/****************************************************************************\
 * BST.h
 *
 *  Created on: 2025
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: ?
 *
\***************************************************************************/

#ifndef BST_H_
#define BST_H_

#include <string>
using namespace std;

/** Binary Search Tree node */
struct BSTNode {
	/** Pointer to the parent node. */
	BSTNode* parent;
	/** Pointer to the left child node. */
	BSTNode* left;
	/** Reference to the right child node. */
	BSTNode* right;
	/** Key used to search an element. */
	int key;
	/** Data associated to the element. */
	string data;
	//TODO You can add more fields here if needed

};


/** Binary Search Tree
 * In a Binary search tree:
 * 		Every node y in the left subtree of x  must have y.key < x.key
 *  	Every node y in the right subtree of x  must have y.key > x.key
 *  	The root node has root.parent = null
 *  	Here no keys can be duplicated
 */
class BST {
	private:
		/** Pointer to the root node of the tree, or nullptr if empty */
		BSTNode* m_root;
		//TODO Add your other BST private variables


		/** Minimum: Finds and returns the node with the smallest key */
		BSTNode* _min(BSTNode* x);
		/** Successor: Returns the node following node x in key order in the whole tree */
		BSTNode* _successor(BSTNode* x);

		/** Computes and returns the height of the node x. */
		int _height(BSTNode* x);

        BSTNode* searchNode(int key);

        void swapContent(BSTNode* x, BSTNode* y);

		string removeHelper(BSTNode* current, int key);

        void preOrderHelper(BSTNode* current);
        void inOrderHelper(BSTNode* current);
        void postOrderHelper(BSTNode* current);

		//TODO Add your other BST private helper methods here

	public:
		/** Construct an empty binary search tree. */
		BST();
		/** Destroy and free up the memory allocated by the binary search tree. */
		virtual ~BST();
		/** Prints all the data from the tree in key order (using _min and _successor). */
		void printTree();

		/** Finds a node with (key) from the tree and returns the associated (data) or "" if not found. */
		string search(int key);
		/** Inserts a new node in the tree with given (key, data). */
		void insert(int key, string data);
		/** Deletes a the node with (key) from the tree and returns the associated (data) or "" if not found. */
		string remove(int key);

		/** Computes and returns the height of the tree. */
		int height();

		/** Prints the keys (comma separated) of the tree using an preorder traversal. */
		void preOrder();
		/** Prints the keys (comma separated) of the tree using an inorder traversal. */
		void inOrder();
		/** Prints the keys (comma separated) of the tree using an postorder traversal. */
		void postOrder();

};

#endif /* BST_H_ */
