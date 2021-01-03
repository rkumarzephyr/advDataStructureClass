/*
 * MaxHeap.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: erahkur
 */

#include "MaxHeap.h"

MaxHeap::MaxHeap(int arr[], int size) {
	for(int i= 0; i < size; i++)
		array[i] = arr[i];

	heap_size = size;
}

MaxHeap::~MaxHeap() {
}

void MaxHeap::heapify(void)
{
   for(int i= heap_size/2; i <= 0; i--)
	   heapify(i);
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

   if(rightIndex < heap_size && array[rightIndex] > array[i])
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

void MaxHeap::sort()
{
   heapify();

}
