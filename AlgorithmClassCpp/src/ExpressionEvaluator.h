/*
 * ExpressionEvaluator.h
 *
 *  Created on: Dec 30, 2020
 *      Author: erahkur
 */

#ifndef EXPRESSIONEVALUATOR_H_
#define EXPRESSIONEVALUATOR_H_

#define NUMBER '0'
#define MINUS '-'
#define PLUS '+'
#define MULTIPLY '*'
#define DIVIDE '/'

#include <iostream>
#include "stack"
using namespace std;

class ExpressionEvaluator {

private:
	stack <double> myStack;

	int getOp(std::string::iterator &it, string &s);
public:
	ExpressionEvaluator();
	virtual ~ExpressionEvaluator();

	double evaluate(string s);
};

#endif /* EXPRESSIONEVALUATOR_H_ */
