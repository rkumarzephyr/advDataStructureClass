/*
 * MaxHeap.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: erahkur
 */

#include "MaxHeap.h"
#include <iostream>

using namespace std;

MaxHeap::MaxHeap(int arr[], int size) {
	for(int i= 0; i < size; i++)
		array[i] = arr[i];

	heap_size = size;
}

MaxHeap::~MaxHeap() {
}

void MaxHeap::heapify(void)
{
   for(int i= heap_size/2; i >= 0; i--)
   {
	   heapify(i);
   }
}
void MaxHeap::heapify(int i)
{
   int leftIndex = left(i);
   int rightIndex = right(i);

   int largestIndex;

   if(leftIndex < heap_size && array[leftIndex] > array[i])
	   largestIndex = leftIndex;
   else
	   largestIndex = i;

   if(rightIndex < heap_size && array[rightIndex] > array[largestIndex])
	   largestIndex = rightIndex;

   if(largestIndex != i)
   {
	   //swap a[i] with a[largest]
	   int temp = array[i];
	   array[i] = array[largestIndex];
	   array[largestIndex] = temp;
	   heapify(largestIndex);
   }
}

/**
 * implements merge sort as mentioned
 * in cormen. this method can be called again and it
 * will work, ideally we can remember that a list is
 * already sort, like a boolean isAlreadySorted.
 */
void MaxHeap::sort()
{
   heapify();
   // max element is at array[0]
   int temp = 0;
   int size = heap_size;

   while(heap_size > 0)
   {
	   temp = array[heap_size-1];
	   array[heap_size-1] = array[0];
	   array[0] = temp;
	   heap_size--;
	   heapify(0);
   }

   heap_size = size;
}

/**
 * call this method on heapfied tree
 * and not on sorted one.
 */
int MaxHeap::heap_extract_maximum()
{
   if(heap_size < 1)
	   throw ("error");

   int max = array[0];
   array[0] = array[heap_size-1];
   heap_size--;
   heapify(0);
   return max;
}

void MaxHeap::increaseKey(int i,int key)
{
	if(!(i < heap_size))
		throw ("invalid key");

	array[i] = key;

	while ((i > 0 && array[i] > array[parent(i)])) {

		exchange(i,parent(i));
		i = parent(i);
	}
}

/**
 * insert new leaf node and then
 * have to make sure heap property is
 * maintained by going to parent.
 * in production code we also should check for
 * capacity of internal array.
 */
void MaxHeap::insert(int key)
{
	array[heap_size] = 0;
	heap_size++;
	increaseKey(heap_size-1, key);
}
void MaxHeap::print()
{
	cout<<endl;
	for(int i= 0; i < heap_size;i++)
		cout<<array[i]<<" ";
}
