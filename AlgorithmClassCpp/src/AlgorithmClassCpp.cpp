//============================================================================
// Name        : AlgorithmClassCpp.cpp
// Author      : erahkur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "ExpressionEvaluator.h"
#include "InfixToPostFix.h"
#include "QueueImpl.h"
#include "MaxHeap.h"

using namespace std;

void testBinarySearchTree() {
	BinaryTree<int> *tree = new BinaryTree<int>();
	tree->insert(15);
	tree->insert(18);
	tree->insert(17);
	tree->insert(20);
	tree->insert(6);
	tree->insert(7);
	tree->insert(13);
	tree->insert(9);
	tree->insert(3);
	tree->insert(2);
	tree->insert(4);
	tree->inOrderTreeWalk();
	bool found = tree->searchElement(10);
	cout << "found 10->" << found << endl;
	found = tree->searchElement(10);
	cout << "found 10->" << found << endl;
	Node<int> *foundNode = tree->searchElement(20);
	cout << "found->" << foundNode->key << endl;
	Node<int> *successor = tree->findSuccessor(foundNode);
	if (successor)
		cout << successor->key;

	tree->deleteNode(foundNode); // ideally we should delete this
	delete foundNode;
	cout << "after delete" << endl;
	tree->inOrderTreeWalk();
}

void testExpEvaluator() {

	ExpressionEvaluator evaluator;
	string s = "1 2 - 4 5 + *";
	double result = evaluator.evaluate(s);
	cout << result << endl;

	s = "1 2 - 4 5 + /";
	result = evaluator.evaluate(s);
	cout << result << endl;

}

void testInfixToPostfixExpEvaluator() {

	InfixToPostFix ifx;
	//cout<<ifx.evaluate("A * B")<<endl;
	cout<<ifx.evaluate("(A * B)")<<endl;

}


void testQueue() {

	QueueImpl<int> *queue = new QueueImpl<int>();
	Node<int> *ptr = NULL;
	queue->insert(10);
	queue->insert(20);
	queue->insert(30);
	queue->insert(40);
	queue->display();

	while((ptr = queue->get()) != NULL)
	{
		cout<<ptr->key<<endl;
		delete ptr;
		ptr = NULL;
	}

	if (queue->empty())
		cout << "OK";
	else
		cout << "NOK";

}

void testHeapSort()
{
   int array[10] = {41, 18, 63, 27, 19, 15, 11, 29, 26, 24};

   MaxHeap m(array,10);
   m.sort();
   cout<<endl<<"final"<<endl;
   m.print();
   m.sort(); // check that calling sort again is not a problem
   cout<<endl<<"final2"<<endl;
   cout<<endl;
   m.print();

}

void testHeapSortMax_priorityQueue()
{
	int array[10] = { 41, 18, 63, 27, 19, 15, 11, 29, 26, 24 }; // can keep 10 elements

	MaxHeap m(array, 10);

	m.heapify();

	m.increaseKey(0, 65);

	if (m.heap_extract_maximum() == 65)
		cout << "OK" << endl;
	else
		cout << "NOK" << endl;

	if (m.heap_extract_maximum() == 41)
		cout << "OK" << endl;
	else
		cout << "NOK" << endl;

	m.increaseKey(7, 100);
	if (m.heap_extract_maximum() == 100)
		cout << "OK" << endl;
	else
		cout << "NOK" << endl;

	m.insert(100);
	m.print();
}


int main() {
	//testBinarySearchTree();

	//testExpEvaluator();

	//testInfixToPostfixExpEvaluator();

	//testQueue();

	//testHeapSort();
	testHeapSortMax_priorityQueue();

	return 0;
}
