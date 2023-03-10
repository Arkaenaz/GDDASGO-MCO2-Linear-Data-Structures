/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "algorithms.h"

int main() {
	
	// Your code here
	char infix[257] = "";
	char postfix[257] = "";	
	int nEvaluate;

	fgets(infix, 256, stdin);
	while(strcmp(infix,"QUIT")!=0){
		infixToPostfix(infix,postfix);
		printf("%s\n",postfix);
		
		nEvaluate = evaluatePostfix(postfix);

		if(nEvaluate == -1){
			printf("Division error by zero!\n\n");
		}
		else{
			printf("%d\n\n",nEvaluate);
    	}

		fgets(infix, 256, stdin);
		strcpy(postfix,"");
	}

	return 0;
}

