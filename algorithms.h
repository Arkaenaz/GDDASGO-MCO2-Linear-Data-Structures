/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#ifndef ALGO_H
#define ALGO_H

#include "stack.h"
#include "queue.h"
#include "string.h"
#include "stdlib.h"

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

int isHigherOperand(int nOp, stack *pStack){
	if(top(pStack) == NULL){
		return 0;
	}
	int nTopOp = checkOperand(top(pStack));
	if(nOp <= nTopOp){
		return 1;
	}
	return 0;
}

void popOp(int nOp, stack *pStack, char *postfix){
	int nGo = checkOperand(top(pStack));
	char strTemp[3];
	while(nOp<=nGo){
		if(checkOperand(top(pStack)) == 0 || checkOperand(top(pStack)) == 5){
				pop(&pStack);
		}
		else{
			strcpy(strTemp,pop(&pStack));
			strcat(strTemp, " ");
			strcat(postfix,strTemp);
		}
		
		nGo = isHigherOperand(nOp, pStack);

		if(top(pStack) == NULL){
			nGo = -1;
		}
	}
}

void infixToPostfix(char *infix, char *postfix) {
	// Your code here
	stack* pStack = createStack(10);
	int nOp;
	char strTemp[257] = "";

	int i;
	for(i = 0; i<=strlen(infix); i++){
		if(*(infix+i) != ' ' && *(infix+i) != '\0'){
			strncat(strTemp,infix+i,1);
		}
		else if(*(infix+i) == ' '){
			//failsafe if strTemp is empty for some reason
			if(strTemp[0]!='\0'){
				nOp = checkOperand(strTemp);
				switch(nOp){
					case 0:
						push(&pStack,strTemp);
						break;
					case 1:case 2:case 3:case 4:
						if(isHigherOperand(nOp,pStack) == 1){
							popOp(nOp,pStack,postfix);
							push(&pStack,strTemp);
						}
						else{
							push(&pStack,strTemp);
						}
						break;
					case 5:
						pop(&pStack);
						popOp(1,pStack,postfix);
						break;
					default:
						strcat(strTemp," ");
						strcat(postfix, strTemp);
						break;
				}
				strTemp[0] = '\0';
			}
		}
	}
	if(strcmp(strTemp,")") != 0){
		strcat(strTemp," ");
		strcat(postfix, strTemp);
	}
	popOp(0,pStack,postfix);

}

int evaluatePostfix(char *postfix) {
	// Your code here
	stack* pStack = createStack(10);
	int i,n1,n2;
	char strTemp[256] = "";
	char *empty;
	

	for(i = 0; i<=strlen(postfix); i++){
		if(*(postfix+i) != ' ' && *(postfix+i) != '\0'){
			strncat(strTemp,postfix+i,1);
		}
		else if(*(postfix+i) == ' '){
			//failsafe if strTemp is empty for some reason
			if(strTemp[0]!='\0'){
				if(strcmp(strTemp,"+") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					sprintf(strTemp,"%d",n1+n2);
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"-") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					sprintf(strTemp,"%d",n1-n2);
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"/") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n2 == 0){
						return -1;
					}
					sprintf(strTemp,"%d",n1/n2);
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"*") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					sprintf(strTemp,"%d",n1*n2);
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"!") == 0){
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 == 0){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"&&") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 != 0 && n2 != 0){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"||") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 != 0 || n2 != 0){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,">") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 > n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"<") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 < n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,">=") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 >= n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"<=") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 <= n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"!=") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 != n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else if(strcmp(strTemp,"==") == 0){
					n2 = (int)strtol(pop(&pStack),&empty,10);
					n1 = (int)strtol(pop(&pStack),&empty,10);
					if(n1 == n2){
						sprintf(strTemp,"%d",1);
					}
					else{
						sprintf(strTemp,"%d",0);
					}
					push(&pStack,strTemp);
				}
				else{
					push(&pStack,strTemp);
				}
			}
			strTemp[0] = '\0';
		}
	}

	return (int)strtol(pop(&pStack),&empty,10);
}

#endif