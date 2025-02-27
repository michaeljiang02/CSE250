/****************************************************************************\
 * BST.cpp
 *
 *  Created on: 2025
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: \\TODO
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
 *
\***************************************************************************/

#include <iostream>
#include "BST.h"
using namespace std;

/** Minimum: Finds and returns the node with the smallest key */
BSTNode* BST::_min(BSTNode* x) {
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

/**Successor: Returns the node following node x in key order in the whole tree */
BSTNode* BST::_successor(BSTNode* x) {
	if (x->right == nullptr) {
        int value = x->key;
        BSTNode* walker = x->parent;
        while (walker != nullptr && walker->key < value) {
            walker = walker->parent;
        }
        return walker;
    } else {
       return _min(x->right);
    }
}

/** Computes and returns the height of the node x. */
int BST::_height(BSTNode* x) {
	if (x == nullptr) {
        return -1;
    }
    return 1 + max(_height(x->left), _height(x->right));
}

/** Construct an empty binary search tree. */
BST::BST() {
	m_root = nullptr;
}

/** Destroy and free up the memory allocated by the binary search tree. */
BST::~BST() {
	// TODO
}

/** Prints all the data from the tree in key order (using _min and _successor).
 *  The output should look like [(3,Hello), (8,RMC), (21,Student)] \n
 */
void BST::printTree() {
    if (m_root == nullptr) {
        cout << "[]" << endl;
    }
	BSTNode* current = _min(m_root);
    cout << "[";
    while (_successor(current) != nullptr) {
        cout << "(" << current->key << "," << current->data << ")" << ", ";
        current = _successor(current);
    }
    cout << "(" << current->key << "," << current->data << ")" << "]" << endl;
}


/** Finds a node with (key) from the tree and returns the associated (data) or "" if not found. */
string BST::search(int key) {
	BSTNode* walker = m_root;
    while (walker != nullptr) {
        if (key == walker->key) {
            return walker->data;
        } if (key < walker->key) {
            walker = walker->left;
        } else {
            walker = walker->right;
        }
    }
    return "";
}

BSTNode* BST::searchNode(int key) {
    BSTNode* walker = m_root;
    while (walker != nullptr) {
        if (key == walker->key) {
            return walker;
        } if (key < walker->key) {
            walker = walker->left;
        } else if (key > walker->key) {
            walker = walker->right;
        }
    }
    return walker;
}

/** Inserts a new node in the tree with given (key, data). */
void BST::insert(int key, string data) {
    BSTNode* x = new BSTNode();
    x->key = key;
    x->data = data;
    x->left = nullptr;
    x->right = nullptr;
    if (m_root == nullptr) {
        m_root = x;
        m_root->parent = nullptr;
        return;
    }
    BSTNode* walker = m_root;
    BSTNode* parent = walker->parent;
    while (walker != nullptr) {
        parent = walker;
        if (key < walker->key) {
            walker = walker->left;
        } else {
            walker = walker->right;
        }
    }
    if (key < parent->key) {
        parent->left = x;
    }
    else {
        parent->right = x;
    }
    x->parent = parent;
}

void BST::swapContent(BSTNode *x, BSTNode* y) {
    int keyholder = x->key;
    string dataholder = x->data;
    x->key = y->key;
    x->data = y->data;
    y->key = keyholder;
    y->data = dataholder;
}

/** Deletes a the node with (key) from the tree and returns the associated (data) or empty string "" if not found. */
string BST::remove(int key) {
    BSTNode* current = searchNode(key);
    // Case 1: Not found
    if (current == nullptr) {
        return "";
    }
	// Case 2: two children
    if (current->left != nullptr && current->right != nullptr) {
        BSTNode* successor = _successor(current);
        swapContent(current, successor);
        return remove(key);
    }
    // Case 3: one child
    if (current->left != nullptr){
        BSTNode* left = current->left;
        swapContent(current, left);
        return remove(key);
    }
    if (current->right != nullptr){
        BSTNode* right = current->right;
        swapContent(current, right);
        return remove(key);
    }
    // Case 4: no children
     else {
         string returnValue = current->data;
         delete current;
         return returnValue;
     }
}


/** Computes and returns the height of the tree. */
int BST::height() {
    return _height(m_root);
}


/** Prints the keys (comma separated) of the tree using an preorder traversal. */
void BST::preOrder() {
    inOrderHelper(m_root);
    cout << endl;
}


void BST::preOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    cout << current->key << ", ";
    inOrderHelper(current->left);
    inOrderHelper(current->right);
}

/** Prints the keys (comma separated) of the tree using an inorder traversal. */
void BST::inOrder() {
    inOrderHelper(m_root);
    cout << endl;
}


void BST::inOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    inOrderHelper(current->left);
    cout << current->key << ", ";
    inOrderHelper(current->right);
}

/** Prints the keys (comma separated) of the tree using an postorder traversal. */
void BST::postOrder() {
    inOrderHelper(m_root);
    cout << endl;
}

void BST::postOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    inOrderHelper(current->right);
    cout << current->key << ", ";
    inOrderHelper(current->left);
}

