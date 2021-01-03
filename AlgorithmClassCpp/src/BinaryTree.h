/*
 * BinaryTree.h
 *
 *  Created on: Dec 24, 2020
 *      Author: erahkur
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdlib.h>
#include <stdio.h>


/**
 * A tree is ADT with a root node and other nodes
 * which are subtrees of root node; the subtrees are disjoint sets i.e there is
 * nothing common in them. Number of subtrees of a node is called 'degree'
 * so a node with degree zero is called leaf node.
 */

/**
 *
 */
using namespace std;

/**
 * Node will need to be changed to have some data as well
 * if this code needs to be used for some kind of production use
 * but that would be straight forward.
 */
template<class T>
class Node {
public:
	Node(T aKey)
	{
		parent = NULL;
		right = NULL;
		left = NULL;
		this->key = aKey;
		isDummy = false;
	}
	Node *parent;
	Node *right;
	Node *left;
	T key;
	bool isDummy;
};


template<class T>
class BinaryTree {
private:
	Node<T> *myRoot;
	void inOrderWalk(Node<T> *ptr) {
		if (ptr) {
			inOrderWalk(ptr->left);
			cout << ptr->key << ",";
			inOrderWalk(ptr->right);
		}
	}

	Node<T> * search(Node<T> *ptr, T value) {
		if ((ptr == NULL) || (ptr->key == value)) {
		return ptr;
		}

		if (ptr->key < value)
			return search(ptr->right, value);
		else
			return search(ptr->left, value);
	}
public:
	BinaryTree() {
    myRoot = NULL;
	}

	bool isEmpty()
	{
		return myRoot == NULL;
	}

	/**
	 * prints tree in inorder that
	 * left->root->right
	 */
	void inOrderTreeWalk() {
		if (myRoot) {
			inOrderWalk(myRoot);
		}
	}

	/**
	 *
	 */
	Node<T>* searchElement(T value)
	{
		return search(myRoot, value);
	}

	/**
	 * finds the successor of given node.
	 * Successor is the smallest node with
	 * key greater than given node. if right subtree of
	 * node is not empty then the successor is left most node
	 * in right subtree.
	 */
	Node<T>* findSuccessor(Node<T> *x) {
		if (x->right != NULL) {
			return treeMinimum(x->right);
		}

		Node<T> *y = x->parent;
		while (y != NULL && x == y->right) {
			x = y;
			y = y->parent;
		}

		return y;
	}

	Node<T>* treeMinimum(Node<T> *x)
	{
		while(x->left != NULL)
		{
			x = x->left;
		}

		return x;
	}
	/**
	 * insert T into tree.
	 */
	void insert(T dataToInsert) {
		// create node with T
		Node<T> *treePtr = myRoot;
		Node<T> *tempPtr = NULL; // to keep the last good position.
		while (treePtr != NULL) {
			tempPtr = treePtr;
			if (treePtr->key < dataToInsert)
				treePtr = treePtr->right;
			else
				treePtr = treePtr->left;

		}

		Node<T> *nodeToInsert = new Node<T>(dataToInsert);
		nodeToInsert->parent = tempPtr;
		if (tempPtr == NULL) {
			myRoot = nodeToInsert; // make root
		} else if (tempPtr->key < dataToInsert) {
			tempPtr->right = nodeToInsert;
		} else {
			tempPtr->left = nodeToInsert;
		}
	}

	/**
	 * transplants tree so that v replaces u subtree.
	 */
	void transplant(Node<T> *u, Node<T> *v)
	{
		if(u->parent == NULL)
		{
			myRoot = v;
		}else if( u == u->parent->left)
		{
			u->parent->left = v;
		}else
		{
			u->parent->right = v;
		}

		if(v != NULL)
		{
			v->parent = u->parent;
		}
	}

	/**
	 * delete
	 * case 1. z has no children that is z is leaf
	 * this is easy we simply make z.p = NULL
	 * case 2. if z has just one child we make child take position
	 * of z.
	 * case 3. if z has two children, y = successor(z) have y take position
	 * of z. but this is tricky since it matter wheather y is right child or not.
	 *
	 * we deal with 4 cases
	 * z has no left child that mean right could be null or not
	 * replace z by y
	 *
	 * if only left then we replace by left.
	 *
	 * if z has both children then if y is not direct right child of z we first transplant
	 * y by right child of y and then transplant z with y.
	 */
	void deleteNode(Node<T>* z)
	{
		if (z->left == NULL) {
			transplant(z, z->right);
		} else if (z->right == NULL) {
			transplant(z, z->left);
		} else {
           Node<T> * y = treeMinimum(z->right);
           if(y->parent != z)
           {
        	   transplant(y, y->right);
        	   y->right = z->right;
        	   y->right->parent = y;
           }
           transplant(z, y);
           y->left = z->left;
           y->left->parent = y;
		}
	}
};


#endif /* BINARYTREE_H_ */
