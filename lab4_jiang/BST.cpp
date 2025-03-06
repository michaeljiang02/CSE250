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
    string value = current->data;
    if (current->left != nullptr && current->right != nullptr) {
        BSTNode* successor = _successor(current);
        swapContent(current, successor);
        current = successor;
    }
    else if (current->left == nullptr || current->right == nullptr) {
        BSTNode* child;
        if (current->left == nullptr) {
            child = current->right;
        } if (current->right == nullptr) {
            child = current->left;
        }
        current->key = child->key;
        current->data = child->data;
        current->left = child->left;
        current->right = child->right;
        delete child;
    }
    else {
        if (current == m_root) {
            m_root = nullptr;
            return value;
        }
        delete current;
    }
    return value;
}


// string BST::remove(int key) {
//     return removeHelper(m_root, key);
// }
//
// string BST::removeHelper(BSTNode* current, int key) {
//     if (current == nullptr) {
//         return "";
//     }
//     if (key < current->key) {
//         return removeHelper(current->left, key);
//     }
//     if (key > current->key) {
//         return removeHelper(current->right, key);
//     }
//     if (key == current->key) {
//         string value = current->data;
//         // Case 1: No children
//         if (current->left == nullptr && current->right == nullptr) {
//             if (current == m_root) {
//                 m_root = nullptr;
//                 return value;
//             }
//             if (current->key < current->parent->key) {
//                 current->parent->left = nullptr;
//             } if (current->key > current->parent->key) {
//                 current->parent->right = nullptr;
//             }
//             delete current;
//             return value;
//         }
//         // // Case 2: 1 child
//         if (current->left == nullptr || current->right == nullptr) {
//             BSTNode* child;
//             if (current->left == nullptr) {
//                 child = current->right;
//             } if (current->right == nullptr) {
//                 child = current->left;
//             }
//             current->key = child->key;
//             current->data = child->data;
//             current->left = child->left;
//             current->right = child->right;
//             delete child;
//             return value;
//         }
//         // Case 3: 2 children
//         BSTNode* successor = _successor(current);
//         current->key = successor->key;
//         current->data = successor->data;
//         successor->key++;
//         removeHelper(current->right, successor->key);
//         return value;
//     }
// }

/** Computes and returns the height of the tree. */
int BST::height() {
    return _height(m_root);
}


/** Prints the keys (comma separated) of the tree using an preorder traversal. */
void BST::preOrder() {
    preOrderHelper(m_root);
    cout << endl;
}


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

void BST::postOrderHelper(BSTNode *current) {
    if (current == nullptr) {
        return;
    }
    postOrderHelper(current->left);
    postOrderHelper(current->right);
    cout << current->key << ", ";
}

