/*
 * ExpressionEvaluator.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: erahkur
 */

#include <ctype.h>
#include "ExpressionEvaluator.h"

using namespace std;

ExpressionEvaluator::ExpressionEvaluator() {

}

ExpressionEvaluator::~ExpressionEvaluator() {
	// TODO Auto-generated destructor stub
}

double ExpressionEvaluator::evaluate(string s) {
	double op1;
	double op2;
	for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
		string str;
		switch (getOp(it, str)) {
		case NUMBER:
			myStack.push(atof(str.c_str()));
			break;
		case MINUS:
			op2 = myStack.top();
			myStack.pop();
			op1 = myStack.top();
			myStack.pop();
			myStack.push(op1 - op2);
			break;
		case PLUS:
			op1 = myStack.top();
			myStack.pop();
			op2 = myStack.top();
			myStack.pop();
			myStack.push(op1 + op2);
			break;
		case MULTIPLY:
			op1 = myStack.top();
			myStack.pop();
			op2 = myStack.top();
			myStack.pop();
			myStack.push(op1 * op2);
			break;
		case DIVIDE:
			op2 = myStack.top();
			myStack.pop();
			op1 = myStack.top();
			myStack.pop();
			myStack.push(op1 / op2);
			break;
		}
	}
	double value = myStack.top();
	myStack.pop();
	return value;
}

// todo handle decimal part of digit
int ExpressionEvaluator::getOp(std::string::iterator &it, string &s) {
	char ch = *it;
	char charArray[10]; // max size 10 of one symbol
	int i = 0;
	int returnType;
	while (ch == ' ')
		ch = *(++it);
	if (isdigit(ch)) {
		charArray[i++] = ch;
		returnType = NUMBER;
	}

	if (ch == '-')
		return MINUS;
	if (ch == '+')
		return PLUS;
	if (ch == '*')
		return MULTIPLY;
	if (ch == '/')
		return DIVIDE;

	charArray[i] = '\0';

	s.append(charArray);

	return returnType;
}

