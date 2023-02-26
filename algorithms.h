/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#include "stack.h"
#include "string.h"
#include "stdlib.h"

void convertToken(char *infix, char *postfix){

}

int getLen(char *infix, int i){
	char cTemp;
	int j = 0;
	do{
		cTemp = *(infix+i+j);
		j += 1;
	}while(cTemp != ' ' && cTemp != '\0');
	return j;
}

int checkOperand(char *strTemp){
	if(strcmp(strTemp,"(") == 0){
		return 0;
	}
	else if(strcmp(strTemp,"+") == 0 || strcmp(strTemp,"-") == 0){
		return 1;
	}
	else if(strcmp(strTemp,"/") == 0 || strcmp(strTemp,"*") == 0){
		return 2;
	}
	else if(strcmp(strTemp,">") == 0 || strcmp(strTemp,"<") == 0 || strcmp(strTemp,">=") == 0 || strcmp(strTemp,"<=") == 0 || strcmp(strTemp,"!=") == 0 || strcmp(strTemp,"==") == 0){
		return 3;
	}
	else if(strcmp(strTemp,"!") == 0 || strcmp(strTemp,"&&") == 0 || strcmp(strTemp,"||") == 0){
		return 4;
	}
	else if(strcmp(strTemp,")") == 0){
		return 5;
	}
	return -1;
}

int isHigherOperand(int nOp, stack *sStack){
	if(top(sStack) == NULL){
		return 0;
	}
	char strTemp[3];
	strcpy(strTemp,top(sStack));
	strTemp[1] = '\0';
	int nTopOp = checkOperand(strTemp);
	printf("check operand: %d  vs  %d,  %s\n\n",nOp,nTopOp,strTemp);
	if(nOp <= nTopOp){
		return 1;
	}
	return 0;
}

void popOp(int nOp, stack *sStack, char *postfix){
	int nGo = 1;
	char strTemp[3];
	do{
		printf("%s\n\n",top(sStack));
		strcpy(strTemp,top(sStack));
		strTemp[1] = '\0';
		if(checkOperand(top(sStack)) == 0){
				pop(&sStack);
		}
		else{
			strcpy(strTemp,pop(&sStack));
			strTemp[1] = '\0';
			strcat(postfix,strTemp);
			strcat(postfix, " ");
		}
		nGo = isHigherOperand(nOp, sStack);

		if(top(sStack) == NULL){
			nGo = -1;
		}
	}while(nOp<=nGo);
}

void infixToPostfix(char *infix, char *postfix) {
	// Your code here
	stack* sStack = createStack(256);
	int nOp;
	char strTemp[256];

	int i;
	for(i = 0; i<strlen(infix); i++){
		if(*(infix+i) != ' ' && *(infix+i) != '\0'){
			strncat(strTemp,infix+i,1);
			printf("%d, %s\n",i,strTemp);
		}
		else if(*(infix+i) == ' '){
			nOp = checkOperand(strTemp);
			switch(nOp){
				case 0:
					push(&sStack,strTemp);
					break;
				case 1:case 2:case 3:case 4:
					//
					if(isHigherOperand(nOp,sStack) == 1){
						popOp(nOp,sStack,postfix);
						push(&sStack,strTemp);
					}
					else{
						push(&sStack,strTemp);
					}
					break;
				case 5:
					popOp(1,sStack,postfix);
					break;
				default:
					strcat(postfix, strTemp);
					break;
			}
			printf("\n%d, %s, postfix  %s\n\n",i,strTemp,postfix);
			strcat(postfix, " ");
			strTemp[0] = '\0';
		}
	}
	strcat(postfix, strTemp);
	strcat(postfix, " ");
	popOp(0,sStack,postfix);
}

int evaluatePostfix(char *postfix) {
	// Your code here
	return 0;
}
