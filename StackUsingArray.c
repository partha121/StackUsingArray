/*
 * StackUsingArray.c
 *
 *  Created on: 19-Aug-2018
 *      Author: partha
 */


#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MIN -1

struct stack
{
        int stack[MAX];
        int top;
};

int pop(struct stack *mystack, int *status)
{
	if(mystack->top == -1){
		printf("stack underflow.\n");
		*status = 0;
		return -1;
	}
	else{
		*status = 1;
		return mystack->stack[mystack->top--];
	}
}

int push(struct stack *mystack, int elem)
{
	if(mystack->top == MAX-1){
		printf("stack overflow.\n");
		return -1;
	}
	else{
		mystack->stack[++mystack->top]=elem;
		return 0;
	}
}

int main()
{
	int n, i, elem, status;
	struct stack mystack;
	mystack.top = -1;
	printf("Please enter the number of elements to stack:");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Please enter the stack element:");
		scanf("%d", &elem);
		push(&mystack, elem);
	}
	printf("The stack contents are:\n");
	for(i = 0; i < n; i++)
	{
		elem = pop(&mystack, &status);
		if(status == 0)//should not happen as we know n here
		{
			break;
		}
		printf("%d ", elem);
	}
	printf("\n");
	return 0;

}
