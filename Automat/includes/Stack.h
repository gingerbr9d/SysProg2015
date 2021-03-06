/*
 * Stack.h
 *
 *  Created on: Nov 12, 2015
 *      Author: arty
 */

#ifndef BUFFER_INCLUDES_STACK_H_
#define BUFFER_INCLUDES_STACK_H_

#define MAX_TOKEN_SIZE 1024

class Stack {
	char *stack;
	int stackHead;
public:
	Stack();
	virtual ~Stack();
	void push(char c);
    void trim(int back);
    void flush();
    char* get();
};

#endif /* BUFFER_INCLUDES_STACK_H_ */
