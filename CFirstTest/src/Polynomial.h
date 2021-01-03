/*
 * Polynomial.h
 *
 *  Created on: Dec 22, 2020
 *      Author: erahkur
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include<stdlib.h>
#include<stdio.h>

/* represents term of a polynomial like 5.5x^3 in a sparse matrix */
typedef struct {
	float coff;
	int exponent;
} PolynomialTerm;

/*
 * represents the polynomial term and points to next element.
 */
typedef struct PolynomialStruct{
	PolynomialTerm * term;
	struct PolynomialStruct *next;
}Polynomial;

Polynomial * createPolyNomialFromArray(float *polynomialArray, int size);
/**
 * creates a node of polynomial with given cofficient and
 * exponent. points next to null
 */
Polynomial * createPolyNomial(float cofficient, int exponent)
{
    Polynomial *poly =  malloc(sizeof(Polynomial));
    poly->term = malloc(sizeof(PolynomialTerm));
    poly->term->coff = cofficient;
    poly->term->exponent = exponent;
    poly->next = NULL;

    return poly;
}

/**
 * adds second polynomial to the end of given polynomial
 * returns -1 if polynomialToAdd cannot be added because base polynomial is null
 */
int addToPolynomial(Polynomial *polynomialBase, Polynomial *polynomialToAdd)
{
	if (polynomialBase == NULL) {
         // if base is null than it means polynomial to add should become base
		return -1;

	}
	Polynomial *head = polynomialBase; // start with first poly
	while(head->next != NULL)
	{
		head = head->next;
	}

	head->next = polynomialToAdd;
	return 0;
}

Polynomial * addPolynomials(Polynomial *polynomial1, Polynomial *polynomial2)
{
	Polynomial *poly1 = polynomial1;
	Polynomial *poly2 = polynomial2;
	Polynomial *result = NULL;
	Polynomial *temp = NULL;
	while ((poly1 != NULL) & (poly2 != NULL)) {
		if (poly1->term->exponent == poly2->term->exponent) {
			temp = createPolyNomial(poly1->term->coff + poly2->term->coff,
					poly1->term->exponent);
			if (addToPolynomial(result, temp) == -1)
				result = temp;
			poly1 = poly1->next;
			poly2 = poly2->next;
		} else if (poly1->term->exponent > poly2->term->exponent) {
			temp = createPolyNomial(poly1->term->coff, poly1->term->exponent);
			if (addToPolynomial(result, temp) == -1)
				result = temp;
			poly1 = poly1->next;
		} else {
			temp = createPolyNomial(poly2->term->coff, poly2->term->exponent);
			if (addToPolynomial(result, temp) == -1)
				result = temp;

			poly2 = poly2->next;
		}
	}

		while (poly1 != NULL) {
			temp = createPolyNomial(poly1->term->coff, poly1->term->exponent);
			if (addToPolynomial(result, temp) == -1)
				result = temp;
			poly1 = poly1->next;
		}

		while (poly2 != NULL) {
			temp = createPolyNomial(poly2->term->coff, poly2->term->exponent);
			if (addToPolynomial(result, temp) == -1)
				result = temp;
			poly2 = poly2->next;
		}

		return result;
}
/*
 * method used to multiply two polynomials
 * start with first term of one polynomial
 */
Polynomial * multiply(Polynomial *polynomial1, Polynomial *polynomial2)
{
   float arrayOfCofficient[MAX_TERMS]; // array to keep the multiplication result
// initilize our array
   for(int i=0; i<MAX_TERMS; i++)
	   arrayOfCofficient[i] = 0.0;

   Polynomial *p = polynomial1;
   while(p)
   {
	   Polynomial *p2 = polynomial2;
	   while(p2)
	   {
          float coff1 = p->term->coff, coff2 = p2->term->coff;
          int exp1 = p->term->exponent, exp2 = p2->term->exponent;

          float coffResult = coff1 * coff2;
          int expResult = exp1 + exp2;

          arrayOfCofficient[expResult] += coffResult;

          p2 = p2->next;
	   }

	   p = p->next;
   }

   createPolyNomialFromArray(&arrayOfCofficient[0], MAX_TERMS);
}

/**
 *
 */

Polynomial * createPolyNomialFromArray(float *polynomialArray, int size)
 {
	Polynomial *polyHead = NULL;
	Polynomial *temp = NULL;
	for (int i = size - 1; i >= 0; i--) {
		if (polynomialArray[i]) {
			temp = createPolyNomial(polynomialArray[i], i);
			if (addToPolynomial(polyHead, temp) == -1)
				polyHead = temp;
		}
	}

	return polyHead;
}

#endif /* POLYNOMIAL_H_ */
