/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

/*
  note: Lines in the code that have "display" at the end are meant for updates to the stack status.
        You may comment the entire lines if they are not necessary.
		!!!displayStacks() & top() is an exception!!!
*/

#include "stdio.h"
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
	printf("A Stack has been created with %d slots!\n\n", n); //display
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

void displayStack(stack *s) {
	sNode *iNode;
	if(!stackEmpty(s)){
		for(int i = 1; i <= s->n; i++){
			iNode = s->pTop;
			if(i <= s->nCount){
				for(int j = s->nCount; j > i; j--){
					iNode = iNode->pLink;
				}
				printf("%c ", *(iNode->data));
			}
			else{
				printf("□ ");
			}
		}
		printf("\n");
		for(int i = 1; i <= s->n; i++){
			if(i == s->nCount) printf("△ ");
			else printf("  ");
		}
		printf("\n\n");
	}
	else{
		printf("Nothing to display...\n\n");
	}
}

void push(stack **s, char *data) {
	if(!stackFull(*s)){
		sNode *sNewNode = malloc(sizeof(sNode));

		char *dat = malloc(sizeof(char));
		*dat = *data;
		
		sNewNode->data = dat;
		if((*s)->nCount != 0){
			sNewNode->pLink = (*s)->pTop;
		}
		(*s)->pTop = sNewNode;
		
		++(*s)->nCount;
		printf("[+] Pushed \"%c\" to stack!\n", *data); //display
		displayStack(*s); //display
	}
	else{
		printf("Stack is currenty full!\n"); //display
	}
}

char* pop(stack **s) {
	if(!stackEmpty(*s)){
		char *data = (*s)->pTop->data;

		(*s)->pTop = (*s)->pTop->pLink;

		--(*s)->nCount;
		printf("[-] Popped stack and returned \"%c\"\n", *data); //display
		displayStack(*s); //display
		return data;
	}
	else{
		printf("Stack is currently empty!"); //display
		return NULL;
	}
	
}

char* top(stack *s) {
	printf("Current Top Data of Stack: %c\n\n", *(s->pTop->data));
	return s->pTop->data;
}
