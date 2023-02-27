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
	else if(strcmp(strTemp,"!") == 0 || strcmp(strTemp,"&&") == 0 || strcmp(strTemp,"||") == 0){
		return 3;
	}
	else if(strcmp(strTemp,">") == 0 || strcmp(strTemp,"<") == 0 || strcmp(strTemp,">=") == 0 || strcmp(strTemp,"<=") == 0 || strcmp(strTemp,"!=") == 0 || strcmp(strTemp,"==") == 0){
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
	int nTopOp = checkOperand(top(sStack));
	if(nOp <= nTopOp){
		return 1;
	}
	return 0;
}

void popOp(int nOp, stack *sStack, char *postfix){
	int nGo = checkOperand(top(sStack));
	char strTemp[3];
	while(nOp<=nGo){
		if(checkOperand(top(sStack)) == 0 || checkOperand(top(sStack)) == 5){
				pop(&sStack);
		}
		else{
			strcpy(strTemp,pop(&sStack));
			strcat(strTemp, " ");
			strcat(postfix,strTemp);
		}
		
		nGo = isHigherOperand(nOp, sStack);

		if(top(sStack) == NULL){
			nGo = -1;
		}
	}
}

void infixToPostfix(char *infix, char *postfix) {
	// Your code here
	stack* sStack = createStack(10);
	int nOp;
	char strTemp[256];

	int i;
	for(i = 0; i<=strlen(infix); i++){
		if(*(infix+i) != ' ' && *(infix+i) != '\0'){
			strncat(strTemp,infix+i,1);
			//("%d, %s\n",i,strTemp);
		}
		else if(*(infix+i) == ' '){
			//failsafe if strTemp is empty for some reason
			if(strTemp[0]!='\0'){
				nOp = checkOperand(strTemp);
				//printf("\n%d\n",nOp);
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
						pop(&sStack);
						popOp(1,sStack,postfix);
						break;
					default:
						strcat(strTemp," ");
						strcat(postfix, strTemp);
						break;
				}
				//printf("\n%d, %s, postfix  %s\n\n",i,strTemp,postfix);
				strTemp[0] = '\0';
			}
		}
	}
	if(strcmp(strTemp,")") != 0){
		strcat(postfix, strTemp);
	}
	popOp(0,sStack,postfix);
}

int evaluatePostfix(char *postfix) {
	// Your code here
	return 0;
}
