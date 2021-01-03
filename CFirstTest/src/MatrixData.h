/*
 * MatrixData.h
 *
 *  Created on: Dec 19, 2020
 *      Author: erahkur
 */

#ifndef MATRIXDATA_H_
#define MATRIXDATA_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 500

struct MatrixElement {
	int row;
	int column;
	int value;
};
/**
 * slow one, see sahni,sparse matrix
 */
int transpose(struct MatrixElement a[], struct MatrixElement bT[]) {
	int totalNumberOfElements = a[0].value;
	// copy dimensioning information in transformed matrix.
	bT[0].row = a[0].column;
	bT[0].column = a[0].row;
	bT[0].value = totalNumberOfElements;

	int currentIndex = 1;

	//loop through all the possible columns like 0 to 1000000
	for (int i = 0; i <= a[0].column; i++) {
		// we skip the first row in sparse matrix
		for (int j = 1; j <= totalNumberOfElements; j++) {
			if(a[j].column == i)
			{
               bT[currentIndex].column = a[j].row;
               bT[currentIndex].row = a[j].column;
               bT[currentIndex].value = a[j].value;
               currentIndex++;

               printf("matched for %d \n", i);
			}
		}
	}

	return 0;
}

/**
 * see sahni,sparse matrix
 */
int fast_transpose(struct MatrixElement a[], struct MatrixElement bT[]) {
	int totalNumberOfElements = a[0].value;
	// copy dimensioning information in transformed matrix.
	bT[0].row = a[0].column;
	bT[0].column = a[0].row;
	bT[0].value = totalNumberOfElements;

	int columnsInMatrix = a[0].column;
	int countingArray[columnsInMatrix];
	int startingPosition[columnsInMatrix];

	for(int i = 0 ;i < columnsInMatrix; i++)
	{
         countingArray[i] = 0; // initialization
         startingPosition[i] = 0;
	}

	for(int i = 1; i <= totalNumberOfElements; i++)
	{
		countingArray[a[i].column]++;
	}

	startingPosition[0] = 1; // starting position is always 1 for column number 0

	for(int i = 1; i <= columnsInMatrix; i++)
	{
		startingPosition[i] = startingPosition[i-1] + countingArray[i-1];
	}

	int k =0;
	for(int i=1; i <= totalNumberOfElements; i++)
	{
       k = a[i].column;

       bT[startingPosition[k]].row = a[i].column;
       bT[startingPosition[k]].column = a[i].row;
       bT[startingPosition[k]].value = a[i].value;

       startingPosition[k]++; // increment so that next insertion takes place at next place.
	}

	return 0;
}

int mymax(int a, int b)
{
	if(a>b)
		return 1;
	else if(a == b)
		return 0;
	else
		return -1;
}

/**
 * multiply sparse matrices a and b resulting into d
 */
int matrix_multiply(struct MatrixElement a[], struct MatrixElement b[],
		struct MatrixElement d[]) {

	int i, j, currentColumn, totalD = 0;
	int rowsA = a[0].row, colsA = a[0].column;

	int totalA = a[0].value, totalB = b[0].value;
	int colsB = b[0].column;

	int rowBegin = 1, sum = 0;

	struct MatrixElement bT[b[0].value];

	if (colsA != b[0].row) {
		printf("error non compatible matrices\n");
		exit(1);
	}

	fast_transpose(b, bT);

	/*
	 * multiply row of a with columns of b
	 * this is mostly from Sahni book, but this algo is not easy to
	 * understand. The algo multiplies the row of marix a with row(columns)
	 * of transposed matrix. what you do is take one row value of a and treat
	 * row in bT matrix and then compare column value, whereever columns match
	 * that part will contribute to the sum.
	 */

	int currentRow = a[1].row;

	for (i = 1; i <= totalA;) {
		currentColumn = bT[1].row;
		for (j = 1; j <= totalB;) {
			if (a[i].row != currentRow) {
				storeSum(d, &totalD, currentRow, currentColumn, &sum);
				i = rowBegin; // make i go to beginning where we had our current row
				for (; bT[j].row == currentColumn; j++)
					;

			} else if (bT[j].row != currentColumn) {
				storeSum(d, &totalD, currentRow, currentColumn, &sum);
				i = rowBegin; // make i go to beginning where we had our current row
				currentColumn = bT[j].row;

			} else {
				// when i am at row which is current row
				switch (mymax(a[i].column, bT[j].column)) {
				case 1:
					j++;
					break;
				case -1:
					i++;
					break;
				case 0:
					sum += (a[i++].value * bT[j].value);
					break;
				}
			}
		} // end of totalB
		for (; a[i].row == currentRow; i++)
			;
		rowBegin = i;
		currentRow = a[i].row;
	}

	d[0].row = rowsA;
	d[0].column = colsB;
	d[0].value = totalD;
	return 0;
}


void storeSum(struct MatrixElement d[], int *totalD, int row, int column,int *sum)
{
	if(*sum)
	{
		if(*totalD < MAX_TERMS)
		{
           d[++*totalD].row = row;
           d[*totalD].column = column;
           d[*totalD].value = *sum;
           *sum = 0;
		}else
		{
			printf("too many elements\n");
			exit(0);
		}
	}
}
void debugPrintMatrix(struct MatrixElement a[]) {
	for (int i = 0; i <= a[0].value; i++) {
		printf("%d %d %d \n", a[i].row, a[i].column,
				a[i].value);
	}
}

int addSparseMatrix(struct MatrixElement matrixOne[],
		struct MatrixElement matrixTwo[], struct MatrixElement matrixResult[]) {

	if (matrixOne[0].row != matrixTwo[0].row
			|| matrixOne[0].column != matrixTwo[0].column) {
		printf("invalid combination for addition of matrix\n");
		return 1;
	}

	int elementsInMatrixOne = matrixOne[0].value;
	int elementsInMatrixTwo = matrixTwo[0].value;

	int i = 1, j = 1, k = 1;

	while ((i <= elementsInMatrixOne) && (j <= elementsInMatrixTwo)) {

		if ((matrixOne[i].row == matrixTwo[j].row)
				&& (matrixOne[i].column == matrixTwo[j].column)) {
			matrixResult[k].row = matrixOne[i].row;
			matrixResult[k].column = matrixOne[i].column;

			matrixResult[k].value = matrixOne[i].value + matrixTwo[j].value;
			++i, ++j, ++k;

		}

		if ((matrixOne[i].row < matrixTwo[j].row)
				|| ((matrixOne[i].row == matrixTwo[j].row)
						&& matrixOne[i].column < matrixTwo[j].column)) {
			matrixResult[k++] = matrixOne[i++];
		}

		if ((matrixOne[i].row > matrixTwo[j].row)
				|| ((matrixOne[i].row == matrixTwo[j].row)
						&& matrixOne[i].column > matrixTwo[j].column)) {
			matrixResult[k++] = matrixTwo[j++];
		}
	}

	while (i <= elementsInMatrixOne)
		matrixResult[k++] = matrixOne[i++];

	while (i <= elementsInMatrixTwo)
		matrixResult[k++] = matrixTwo[j++];

	matrixResult[0].row = matrixOne[0].row;
	matrixResult[0].column = matrixOne[0].column;
	matrixResult[0].value = k - 1; // -1 since k would have been up one extra

	return 0;
}

#endif /* MATRIXDATA_H_ */
