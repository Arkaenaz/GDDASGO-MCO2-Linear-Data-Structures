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

	while(fgets(infix, 256, stdin) != NULL){
		infix[strcspn(infix,"\n")]= '\0';

		if(strcmp(infix, "QUIT") == 0){
			break;
		}

		infixToPostfix(infix,postfix);
		printf("%s\n",postfix);
		
		nEvaluate = evaluatePostfix(postfix);

		if(nEvaluate == -1){
			printf("Division error by zero!\n\n");
		}
		else{
			printf("%d\n\n",nEvaluate);
    	}

		strcpy(postfix,"");

	}

	return 0;
}

