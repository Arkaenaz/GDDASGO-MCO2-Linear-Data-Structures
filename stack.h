/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

/*
  note: Lines in the code that have "display" at the end are meant for updates to the stack status.
        You may comment the entire lines if these updates are not necessary.
		!!!displayStacks() & top() is an exception!!!
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "node.h"

typedef struct {
	int n;
	int nCount;
	sNode *pTop;
} stack;


void printStr(char *strin){
	for(int i = 0; i < strlen(strin); i++){
		printf("%c", strin[i]);
	}
}


stack* createStack(int n) {
	stack *stacky = malloc(sizeof(stack)); 
	stacky->n = n;
	stacky->nCount = 0;
	stacky->pTop = NULL;
	//printf("A Stack has been created with %d slots!\n\n", n); //display
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
				printStr(iNode->data); printf(" ");
			}
			else{
				printf("□ ");
			}
		}
		printf("\n\n");
	}
	else{
		printf("Nothing to display...\n\n");
	}
}

void push(stack **s, char *data) {
	if(!stackFull(*s)){
		//printf("[+] Pushing \"%s\" to stack!\n",data);
		sNode *sNewNode = malloc(sizeof(sNode));

		char *dat = malloc(sizeof(data)+1);
		
		/*for(int i = 0; i < strlen(data); i++){
			*(dat + i) = *(data + i);
		}*/

		strcpy(dat,data);

		dat[strlen(data)+1] = '\0';
		
		sNewNode->data = dat;
		if((*s)->nCount != 0){
			sNewNode->pLink = (*s)->pTop;
		}
		(*s)->pTop = sNewNode;
		
		++(*s)->nCount;
		//printf("[+] Pushed \""); printStr((*s)->pTop->data); printf("\" to stack!\n"); //display
		//displayStack(*s); //display
	}
	else{
		//printf("Stack is currenty full!\n"); //display
	}
}

char* pop(stack **s) {
	if(!stackEmpty(*s)){
		char *data = (*s)->pTop->data;

		(*s)->pTop = (*s)->pTop->pLink;

		--(*s)->nCount;
		//printf("[-] Popped stack and returned \""); printStr(data); printf("\"\n"); //display
		//displayStack(*s); //display
		return data;
	}
	else{
		printf("Stack is currently empty!"); //display
		return NULL;
	}
	
}

char* top(stack *s) {
	if(!stackEmpty(s)){
		//printf("Current Top Data of Stack: %c\n\n", *(s->pTop->data));
		return s->pTop->data;
	}
	else{
		//printf("Nothing to display...\n\n");
		return '\0';
	}
	
}
