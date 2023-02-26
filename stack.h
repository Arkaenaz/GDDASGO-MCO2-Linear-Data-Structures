/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include "stdlib.h"

#include "node.h"

typedef struct {
	int n;
	int nCount;
	sNode *pTop;
} stack;

stack* createStack(int n) {
	stack *stacky = malloc(sizeof(stack)); 
	stacky->n = n;
	stacky->nCount = 0;
	stacky->pTop = NULL;
	return stacky;
}

int stackEmpty(stack *s) {
	if(s->nCount == 0) return 1;
	else return 0;
}

int stackFull(stack *s) {
	if(s->nCount == s->n) return 1;
	else return 0;
}

void push(stack **s, char *data) {
	sNode *sNewNode = malloc(sizeof(sNode));
	char *dat = malloc(sizeof(char));
	*dat = *data;
	sNewNode->data = dat;
	if((*s)->nCount != 0){
		sNewNode->pLink = (*s)->pTop;
	}
	(*s)->pTop = sNewNode;
	
	++(*s)->nCount;
}

char* pop(stack **s) {
	char *data = (*s)->pTop->data;

	(*s)->pTop = (*s)->pTop->pLink;

	--(*s)->nCount;
	return data;
}

void displayStack(stack *s) {
	// Your code here
}

char* top(stack *s) {
	return s->pTop->data;
}
