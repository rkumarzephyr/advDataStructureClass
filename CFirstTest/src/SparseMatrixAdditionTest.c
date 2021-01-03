/*
 * SparseMatrixAdditionTest.c
 *
 *  Created on: Dec 19, 2020
 *      Author: erahkur
 */

#include "MatrixData.h"
#include "Polynomial.h"
#include "Stack.h"
#include "LinkedList.h"

#define MAX_SIZE 100

int runTestMatrixAddition()
{
	//create matrix of 4 rows
	/*
	 * Matrix 1: (4x4)
Row Column Value
1   2       10
1   4       12
3   3       5
4   1       15
4   2       12

Matrix 2: (4X4)
Row Column Value
1   3       8
2   4       23
3   3       9
4   1       20
4   2       25

Result of Addition: (4x4)
Row Column Value
1   2      10
1   3      8
1   4      12
2   4      23
3   3      14
4   1      35
4   2      37
	 */

	struct MatrixElement matA[MAX_SIZE + 1];
	struct MatrixElement matB[MAX_SIZE + 1];
	struct MatrixElement matResult[(2 * MAX_SIZE) + 1];

	// first row stores number of rows/column/nonzero elements.
	matA[0].row = 4; matA[0].column = 4; matA[0].value = 5;
    matA[1].row = 1; matA[1].column = 2; matA[1].value = 10;
    matA[2].row = 1; matA[2].column = 4; matA[2].value = 12;
    matA[3].row = 3; matA[3].column = 3; matA[3].value = 5;
    matA[4].row = 4; matA[4].column = 1; matA[4].value = 15;
    matA[5].row = 4; matA[5].column = 2; matA[5].value = 12;

    matB[0].row = 4; matB[0].column = 4; matB[0].value = 5;
    matB[1].row = 1; matB[1].column = 3; matB[1].value = 8;
    matB[2].row = 2; matB[2].column = 4; matB[2].value = 23;
    matB[3].row = 3; matB[3].column = 3; matB[3].value = 9;
    matB[4].row = 4; matB[4].column = 1; matB[4].value = 20;
    matB[5].row = 4; matB[5].column = 2; matB[5].value = 25;

    addSparseMatrix(matA,matB,matResult);


    printf("result \n");

   for(int i = 1; i< matResult[0].value; i++)
   {
      printf("%d %d %d \n",matResult[i].row, matResult[i].column, matResult[i].value);
   }
	return 0;
}

/*
 * Matrix 1: (4x4)
Row Column Value
1   2       10
1   4       12
3   3       5
4   1       15
4   2       12

Result of transpose on the first matrix: (4x4)
Row Column Value
1   4      15
2   1      10
2   4      12
3   3      5
4   1      12
 */
int runTestMatrixTranspose()
{
	struct MatrixElement matA[MAX_SIZE + 1];
	struct MatrixElement matB[MAX_SIZE + 1];

	// first row stores number of rows/column/nonzero elements.
	matA[0].row = 4; matA[0].column = 4; matA[0].value = 5;
    matA[1].row = 1; matA[1].column = 2; matA[1].value = 10;
    matA[2].row = 1; matA[2].column = 4; matA[2].value = 12;
    matA[3].row = 3; matA[3].column = 3; matA[3].value = 5;
    matA[4].row = 4; matA[4].column = 1; matA[4].value = 15;
    matA[5].row = 4; matA[5].column = 2; matA[5].value = 12;

    transpose(matA, matB);

    for(int i = 0; i<= matB[0].value; i++)
    {
       printf("transposed %d %d %d \n",matB[i].row, matB[i].column, matB[i].value);
    }

    return 0;
}

/*
 * Matrix 1: (4x4)
Row Column Value
1   2       10
1   4       12
3   3       5
4   1       15
4   2       12

Result of transpose on the first matrix: (4x4)
Row Column Value
1   4      15
2   1      10
2   4      12
3   3      5
4   1      12
 */
int runTestMatrixFastTranspose()
{
	struct MatrixElement matA[MAX_SIZE + 1];
	struct MatrixElement matB[MAX_SIZE + 1];

	// first row stores number of rows/column/nonzero elements.
	matA[0].row = 4; matA[0].column = 4; matA[0].value = 5;
    matA[1].row = 1; matA[1].column = 2; matA[1].value = 10;
    matA[2].row = 1; matA[2].column = 4; matA[2].value = 12;
    matA[3].row = 3; matA[3].column = 3; matA[3].value = 5;
    matA[4].row = 4; matA[4].column = 1; matA[4].value = 15;
    matA[5].row = 4; matA[5].column = 2; matA[5].value = 12;

    fast_transpose(matA, matB);

    for(int i = 0; i<= matB[0].value; i++)
    {
       printf("transposed fast %d %d %d \n",matB[i].row, matB[i].column, matB[i].value);
    }

    return 0;
}

//create matrix of 4 rows
	/*
	 * Matrix 1: (4x4)
Row Column Value
1   2       10
1   4       12
3   3       5
4   1       15
4   2       12

Matrix 2: (4X4)
Row Column Value
1   3       8
2   4       23
3   3       9
4   1       20
4   2       25


Result of Multiplication: (4x4)
Row Column Value
1   1      240
1   2      300
1   4      230
3   3      45
4   3      120
4   4      276

*/
int runTestMatrixMultiplication()
{
	struct MatrixElement matA[MAX_SIZE + 1];
		struct MatrixElement matB[MAX_SIZE + 1];

	printf("runn multiplication\n");
		// first row stores number of rows/column/nonzero elements.
		matA[0].row = 4; matA[0].column = 4; matA[0].value = 5;
	    matA[1].row = 1; matA[1].column = 2; matA[1].value = 10;
	    matA[2].row = 1; matA[2].column = 4; matA[2].value = 12;
	    matA[3].row = 3; matA[3].column = 3; matA[3].value = 5;
	    matA[4].row = 4; matA[4].column = 1; matA[4].value = 15;
	    matA[5].row = 4; matA[5].column = 2; matA[5].value = 12;

	    matB[0].row = 4; matB[0].column = 4; matB[0].value = 5;
	    matB[1].row = 1; matB[1].column = 3; matB[1].value = 8;
	    matB[2].row = 2; matB[2].column = 4; matB[2].value = 23;
	    matB[3].row = 3; matB[3].column = 3; matB[3].value = 9;
	    matB[4].row = 4; matB[4].column = 1; matB[4].value = 20;
	    matB[5].row = 4; matB[5].column = 2; matB[5].value = 25;

	    struct MatrixElement matResult[matA[0].row * matB[0].column];

	    matrix_multiply(matA, matB, matResult);

	    debugPrintMatrix(matResult);

    return 0;
}

void runTestPolynomialCreation() {
	Polynomial *polyHead1 = createPolyNomial(10.0, 99); //10x^99
	Polynomial *poly = createPolyNomial(9.0, 2); // 9x^2
	Polynomial *poly1 = createPolyNomial(9.0, 0); // 9x^0

	addToPolynomial(polyHead1, poly);
	addToPolynomial(polyHead1, poly1);

	Polynomial *polyHead2 = createPolyNomial(10.0, 98); //10x^98
	Polynomial *poly2 = createPolyNomial(9.0, 2); // 9x^2
	Polynomial *poly3 = createPolyNomial(9.0, 0); // 9x^0

	addToPolynomial(polyHead2, poly2);
	addToPolynomial(polyHead2, poly3);

	Polynomial * result = addPolynomials(polyHead1, polyHead2);

	while (result != NULL) {
		printf("%f x^%d + ", result->term->coff, result->term->exponent);
		result = result->next;
	}
}

void runTestPolynomialMultiplication() {
	Polynomial *polyHead1 = createPolyNomial(10.0, 99); //10x^99
	Polynomial *poly = createPolyNomial(9.0, 2); // 9x^2
	Polynomial *poly1 = createPolyNomial(9.0, 0); // 9x^0

	addToPolynomial(polyHead1, poly);
	addToPolynomial(polyHead1, poly1);

	Polynomial *polyHead2 = createPolyNomial(10.0, 98); //10x^98
	Polynomial *poly2 = createPolyNomial(9.0, 2); // 9x^2
	Polynomial *poly3 = createPolyNomial(9.0, 0); // 9x^0

	addToPolynomial(polyHead2, poly2);
	addToPolynomial(polyHead2, poly3);

	Polynomial * result = multiply(polyHead1, polyHead2);

	// result should be 100x^197 + 90x^101 + 90x^100 + 90x^99 + 90x^98 + 81x^4 + 162x^2 + 81x^0
	while (result != NULL) {
			printf("%f x^%d + ", result->term->coff, result->term->exponent);
			result = result->next;
		}


}

void runStackUsingLinkedRepresenation()
{
	Stack sp = createStack(10.99);
	sp = push(sp, 20.00);
	sp = push(sp, 13.99);
	printStack(sp);
	double popValue = 0.0;
	sp = pop(sp, &popValue);
	sp = pop(sp, &popValue);
	sp = pop(sp, &popValue);
	sp = pop(sp, &popValue);
	sp = pop(sp, &popValue);

	sp = push(sp,2.0);

	printStack(sp);
}

void runLinkedList() {
	NodeListPtr np = insert(NULL, 1);
	np = insert(np, 2);
	printList(np);
	np = deleteFromList(np, np);
	printList(np);
	np = insert(np, 3);
	// find node with data 3 and get the pointer

	NodeListPtr nodeToDelete = findNode(np, 3);

	np = insert(np, 4);
	np = insert(np, 5);
	printList(np);

	np = deleteFromList(np, nodeToDelete);

	printList(np);
}

void runBinaryTreeTests()
{

}
int main() {
	//runTestMatrixAddition();

	//runTestMatrixTranspose();

	//runTestMatrixFastTranspose();

	//runTestMatrixMultiplication();

	//runTestPolynomialCreation();
	//runTestPolynomialMultiplication();
	//runStackUsingLinkedRepresenation();

	//runLinkedList();
	runBinaryTreeTests();
}
