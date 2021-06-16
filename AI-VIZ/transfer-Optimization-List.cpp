#include "transfer-Optimization-List.h"
#include <stdlib.h>

transferOptimizationList::transferOptimizationList() {
	head = NULL;
	tailNode = NULL;
}

transferOptimizationList::~transferOptimizationList() {
	clear();
}

void transferOptimizationList::addNode(double(*transferFunction)(double), int blockSize) {
	transferOptimizationListNode* addNode = (transferOptimizationListNode*) malloc(sizeof(transferOptimizationListNode));
	addNode->size = blockSize;
	addNode->transferFunction = transferFunction;
	addNode->nextNode = NULL;
	head == NULL ? head = addNode : tailNode->nextNode = addNode;
	tailNode = addNode;
}

transferOptimizationListNode* transferOptimizationList::getHead() {
	return head;
}

void transferOptimizationList::clear() {
	transferOptimizationListNode* curNode = head;
	transferOptimizationListNode* freePtr = head;

	while (curNode != NULL) {
		freePtr = curNode;
		curNode = curNode->nextNode;
		free(freePtr);
	}
	head = NULL;
	tailNode = NULL;
}
