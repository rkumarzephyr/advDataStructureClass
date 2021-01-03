/*
 * InfixToPostFix.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: erahkur
 */

#include <iostream>
#include <string>
#include <ctype.h>

#include "InfixToPostFix.h"
#include "ExpressionEvaluator.h"

using namespace std;

InfixToPostFix::InfixToPostFix() {
	// TODO Auto-generated constructor stub

}

InfixToPostFix::~InfixToPostFix() {
	// TODO Auto-generated destructor stub
}

string InfixToPostFix::evaluate(string infix)
{
	string s,outputStr;
	const string empty(" ");
	char c;

	for (std::string::iterator it = infix.begin(); it != infix.end();) {

		switch(getOp(it, s))
		{
		case OPEN_BRACE:
		case OPERATOR:
			if(!myStack.empty())
			{
				c = myStack.top();
				myStack.pop();
				while (inStackPriority(c) >= inExpressionPriority(s[0])) {
					outputStr.append(empty);
					outputStr.append(string(1, c));
					myStack.pop();
					c = myStack.top();
				}
				myStack.push(c);
			}
			myStack.push(s[0]);
			break;
		case CLOSE_BRACE:
			while(myStack.top() != '(')
			{
				outputStr.append(empty);
				outputStr.append(string(1,myStack.top()));
				myStack.pop();
			}
			myStack.pop(); // remove '('
			break;

		case NUMBER:
			if (!outputStr.length() == 0)
				outputStr.append(empty);
			outputStr.append(s);
			break;
		}

	}

	while(!myStack.empty())
	{
		outputStr.append(empty);
		outputStr.append(string(1,myStack.top()));
		myStack.pop();
	}

	return outputStr;
}

int InfixToPostFix::getOp(std::string::iterator &it, string &s) {
	char ch = *it;
	char charArray[10]; // max size 10 of one symbol
	int i = 0;
	int returnType = 0;;
	while (ch == ' ')
		ch = *(++it);
	if (ch == '(') {
		charArray[i++] = '(';
		++it;
		returnType = OPEN_BRACE;
	}
	if (ch == ')') {
		charArray[i++] = ')';
		++it;
		returnType = CLOSE_BRACE;
	}

	if(ch == '-' || ch == '+' || ch == '/' || ch == '*')
	{
		++it;
		charArray[i++] = ch;
		returnType = OPERATOR;
	}
	if (isalnum(ch)) {
		++it;
		charArray[i++] = ch;
		returnType = NUMBER;
	}
	charArray[i] = '\0';
	s = charArray;
	return returnType;
}

/**
 * '(' has highest in expression priority
 */
int InfixToPostFix::inExpressionPriority(char C) {
	switch (C) {
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 4;
	default:
		return 0;
	}
}

/*
 * '(' has lowest in stack priority
 */
int InfixToPostFix::inStackPriority(char C) {
	switch (C) {
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 1;
	default:
		return 0;
	}
}


