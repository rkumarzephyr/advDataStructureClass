/*
 * QueueImpl.h
 *
 *  Created on: Jan 2, 2021
 *      Author: erahkur
 */

#ifndef QUEUEIMPL_H_
#define QUEUEIMPL_H_

#include <iostream>
#include  "BinaryTree.h"
using namespace std;

/**
 * Handle queue which can keep data of T type.
 * allows standard operations add/remove
 */

template<class T>
class QueueImpl {
	Node<T> *rearOfQueue;
public:
	QueueImpl();
	virtual ~QueueImpl();
	Node<T> * get();
	//Node<T> * remove();
	bool insert(T data);
	void display();
	bool empty();
};


template <typename T>
QueueImpl<T>::QueueImpl() {
	rearOfQueue = new Node<T>(-1);
	rearOfQueue->isDummy = true;
	rearOfQueue->right = rearOfQueue; // dummy node points to itself in begining
}

template <typename T>
QueueImpl<T>::~QueueImpl() {

}

template <typename T>
bool QueueImpl<T>::insert(T data)
{
    Node<T> *node = new Node<T>(data);
    node->key = data;
    node->right = rearOfQueue->right;
    rearOfQueue->right = node;

    rearOfQueue = node;
    return true; // for now unbounded queue
}

template <typename T>
bool QueueImpl<T>::empty()
{
	return rearOfQueue->right == rearOfQueue;
}

template <typename T>
Node<T>* QueueImpl<T>::get()
{
   if(!empty())
   {
      Node<T> * first = rearOfQueue->right->right;
      Node<T> *prev = rearOfQueue->right;
      prev->right = first->right;
		if (first == rearOfQueue) // special case when there is dummy + one node read should be moved.
			rearOfQueue = prev->right;
      return first;
   }

   return NULL;
}

template <typename T>
void QueueImpl<T>::display()
{
   if(!empty())
   {
	   Node<T> * travel = rearOfQueue->right->right; // skip dummy node.

		while (travel != rearOfQueue) {
			cout << travel->key << " ";
			travel = travel->right;
		}
		cout<<travel->key;
	}

   cout<<endl;
}

#endif /* QUEUEIMPL_H_ */
