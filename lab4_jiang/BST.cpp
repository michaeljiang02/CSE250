/****************************************************************************\
 * BST.cpp
 *
 *  Created on: March 13th 2025
 *      Author: Michael Jiang

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
    }
    return _min(x->right);

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
	postOrderRemove(m_root);
}

/** Delete each node through post order traversal, this ensures that we don't delete the parent before the child. */
void BST::postOrderRemove(BSTNode* current) {
    if (current == nullptr) {
        return;
    }
    postOrderRemove(current->left);
    postOrderRemove(current->right);
    delete current;
}

/** Prints all the data from the tree in key order (using _min and _successor).
 *  The output should look like [(3,Hello), (8,RMC), (21,Student)] \n
 */

void BST::printTree() {
    if (m_root == nullptr) {
        cout << "[]" << endl;
        return;
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

/** Finds a node with (key) from the tree and returns the node or NULL if not found. */
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

/** Deletes a the node with (key) from the tree and returns the associated (data) or empty string "" if not found. */

string BST::remove(int key) {
    BSTNode* curr = searchNode(key);

    if (curr == nullptr) {
        return "";
    }
    string value = curr->data;
    BSTNode* parent = curr->parent;

    // Case 1: two children
    if (curr->left && curr->right) {
        BSTNode* successor = _successor(curr);
        BSTNode* successorParent = successor->parent;
        curr->key = successor->key;
        curr->data = successor->data;
        curr = successor;
        parent = successorParent;
    }

    // Case 2: One child or no children
    BSTNode* child;
    if (curr->left) {
        child = curr->left;
    } else {
        child = curr->right;
    }

    if (parent == nullptr) {
        m_root = child;
        if (child != nullptr) {
            m_root->parent = nullptr;
        }
    } else if (parent->left == curr) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete curr;
    return value;
}

/** Computes and returns the height of the tree. */
int BST::height() {
    return _height(m_root);
}


/** Prints the keys (comma separated) of the tree using an preorder traversal. */
void BST::preOrder() {
    preOrderHelper(m_root);
    cout << endl;
}

/** Helper function for recursive preOrder traversal. */
void BST::preOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    cout << current->key << ", ";
    preOrderHelper(current->left);
    preOrderHelper(current->right);
}

/** Prints the keys (comma separated) of the tree using an inorder traversal. */
void BST::inOrder() {
    inOrderHelper(m_root);
    cout << endl;
}


/** Helper function for recursive inOrder traversal. */
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
    postOrderHelper(m_root);
    cout << endl;
}

/** Helper function for recursive postOrder traversal. */
void BST::postOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    postOrderHelper(current->left);
    postOrderHelper(current->right);
    cout << current->key << ", ";
}

