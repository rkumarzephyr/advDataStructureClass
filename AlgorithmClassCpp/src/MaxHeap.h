/*
 * MaxHeap.h
 *
 *  Created on: Jan 2, 2021
 *      Author: erahkur
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#define MAX_SIZE 100
class MaxHeap {
	int array[MAX_SIZE];
	int heap_size;
public:
	MaxHeap(int arr[],int size);
	virtual ~MaxHeap();
	void heapify(int i);
	void heapify(void);

	void sort();

	/**
	 * note these methods are different than
	 * cormen since index here starts from 0
	 */
	int left(int i)
	{
		return 2*i + 1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	int parent(int i)
	{
		return (i+1)/2;
	}
};

#endif /* MAXHEAP_H_ */
