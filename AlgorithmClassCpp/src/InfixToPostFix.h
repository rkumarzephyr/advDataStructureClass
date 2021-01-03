/*
 * InfixToPostFix.h
 *
 *  Created on: Dec 31, 2020
 *      Author: erahkur
 */

#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#include "stack"
#include <ctype.h>
using namespace std;

#define OPEN_BRACE '('
#define CLOSE_BRACE ')'
#define OPERATOR '#' // some operator

#define MAX_SIZE 100


class InfixToPostFix {
private:
	stack <char> myStack;
	int getOp(std::string::iterator &it, string &s);
	int inStackPriority(char c);
	int inExpressionPriority(char c);

public:
	InfixToPostFix();
	virtual ~InfixToPostFix();
	string evaluate(string infix);
};

#endif /* INFIXTOPOSTFIX_H_ */
