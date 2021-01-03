/*
 * LinkedList.h
 *
 *  Created on: Dec 26, 2020
 *      Author: erahkur
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct __Node {
	double data;
	struct __Node *next;
} _Node;

typedef _Node *NodeListPtr;

/**
 * inserts/creates the given data and return the head of list.
 * If the list is null then first node is added.
 */
NodeListPtr insert(NodeListPtr np, int data) {
	NodeListPtr newNode = malloc(sizeof(_Node));
	newNode->data = data;
	newNode->next = NULL;
	if (!np) {

		return newNode;
	}
	NodeListPtr temp = np;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
	return np;
}

/**
 * finds and returns first node with given data
 * if no such data exists it will return NULL
 * np pointer to the head of list
 * data data to be compared against the data in the linked list.
 */
NodeListPtr findNode(NodeListPtr np,float data)
{
	NodeListPtr npLocal = np;
	while(npLocal != NULL)
	{
		if(npLocal->data == data)
			return npLocal;
		npLocal = npLocal->next;
	}

	return NULL;
}
NodeListPtr deleteFromList(NodeListPtr np, NodeListPtr nodeToDelete)
{
	NodeListPtr temp = np;
	NodeListPtr previous = np;
	if(np == nodeToDelete)
	{
		// if first node should be deleted
		temp = np->next;
		free(np);
		return temp;
	}

	while(temp != nodeToDelete && temp != NULL)
	{
		previous = temp;
		temp = np->next;
	}

	if(!temp)
		return np; // nothing found to be deleted

	previous->next = temp->next;

	free(temp);

	return np;
}

void printList(NodeListPtr np) {
	NodeListPtr npLocal = np;
	printf("\n data in list ");
	while (npLocal != NULL) {
		printf(", %f", npLocal->data);
		npLocal = npLocal->next;
	}
}

#endif /* LINKEDLIST_H_ */
