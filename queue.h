/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "node.h"

/*void printStr(char *strin){
	for(int i = 0; i < strlen(strin); i++){
		printf("%c", strin[i]);
	}
}*/
typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* createQueue(int n) {
	queue *pQueue = malloc(sizeof(queue));
	pQueue->n = n;
	pQueue->nCount = 0;
	pQueue->pHead = NULL;
	pQueue->pTail = NULL;

	return pQueue;
}

int queueEmpty(queue *q) {
	if (q->pHead == NULL && q->pTail == NULL)
		return 1;
	else
		return 0;
}

int queueFull(queue *q) {
	if (q->nCount == q->n - 1) 
		return 1;
	else
		return 0;
}

void enqueue(queue **q, char *data) {
	/*if (!queueFull(*q)) {
		sNode *pNewNode = malloc(sizeof(sNode));
		char *pData =  malloc(sizeof(data)+1);

		strcpy(pData,data);
		pData[strlen(data)+1] = '\0';

		pNewNode->data = pData;

		printf("copying data.\n");
		if((*q)->nCount != 0){
			pNewNode->pLink = (*q)->pTail;
		}
		(*q)->pTail = pNewNode;
		printf("incrementing count.\n");
		(*q)->nCount++;
		printf("tail is moving.\n");
		(*q)->pTail = (*q)->pTail->pLink;
	}*/
	if (!queueFull(*q)) {
		sNode *pNewNode = malloc(sizeof(sNode));
		char *pData =  malloc(sizeof(data)+1);

		strcpy(pData, data);
		pData[strlen(data)+1] = '\0';
		pNewNode->data = pData;
		if(queueEmpty(*q)) {
			//printf("hi");
			(*q)->pHead = pNewNode;
			(*q)->pTail = (*q)->pHead;
		}
		else {
			(*q)->pTail->pLink = pNewNode;
			(*q)->pTail = (*q)->pTail->pLink;
			//printf("hi");
			
			//printf("hi");
		}
		(*q)->nCount++;
	}
}

char* dequeue(queue **q) {
		char *cData = (*q)->pHead->data;
	if (!queueEmpty(*q)) {
		(*q)->pHead = (*q)->pHead->pLink;
		(*q)->nCount--;
	}
	return cData;
}

void displayQueue(queue *q) {

	sNode *pTemp = q->pHead;
	int nSize = q->n;
	int i;

	//printf("%d", nSize);
	if (!queueEmpty(q)) {
		for (i=0;i<nSize;i++) {
			//if (pTemp->pLink != NULL) {
				//printf("%s ", pTemp->data);
			//	pTemp = pTemp->pLink;
			//}
			if (i <  q->nCount){
				printf("%s ", pTemp->data);
				pTemp = pTemp->pLink;
			}
			else 
				printf("□ ");
			//printf("hi2");
			//if (pTemp->data != NULL) {
			//	printf("hi2");
				//printf("%s ", pTemp->data);
			//	printf("hi2");
			//}
			
		}
		printf("\n");
	}
	else {
		for (i=0;i<nSize;i++) 
			printf("□ ");
		printf("\n");
	}	
}

char* head(queue *q) {
	return q->pHead->data;
}

char* tail(queue *q) {
	return q->pTail->data;
}

#endif
