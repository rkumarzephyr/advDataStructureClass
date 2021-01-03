/*
 * Stack.h
 *
 *  Created on: Dec 26, 2020
 *      Author: erahkur
 *
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct _Stack
{
	struct _Stack *next;
	double data;

}__Stack;

typedef __Stack * Stack;

Stack createStack(double data) {
	Stack sp = malloc(sizeof(__Stack));
	sp->next = NULL;
	sp->data = data;
	return sp;
}

/**
 * pushes data into the stack.
 * returns ref of new stack.
 */
Stack push(Stack sp, double data)
 {
	Stack newnode = malloc(sizeof(__Stack ));
	newnode->next = sp;
	newnode->data = data;
	return newnode;
}

/**
 * Pops from current top of sp and returns new sp.
 * if sp is null does nothing
 */
Stack pop(Stack sp, double *data)
{
	if(!sp)
		return sp;

   Stack temp = sp;
   *data = temp->data;
   sp = sp->next;
   free(temp);
   return sp;
}

void printStack(Stack sp)
{
	Stack spLocal = sp;
    while(spLocal)
    {
    	printf("%f \n" , spLocal->data);
    	spLocal = spLocal->next;
    }
}
#endif /* STACK_H_ */
