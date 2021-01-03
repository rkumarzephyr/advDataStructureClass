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
   int array[10];
   for(int i = 0; i <= 9;i++)
   {
	   array[i] = rand();
	   cout<<array[i]<<" ";
   }

   MaxHeap m(array,10);
   m.heapify();
}
int main() {
	//testBinarySearchTree();

	//testExpEvaluator();

	//testInfixToPostfixExpEvaluator();

	//testQueue();

	testHeapSort();

	return 0;
}
