/*
	Copyright (C) 2021  Jacob Reed Haygood
	This file is part of AI-VIZ.

	Foobar is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Foobar is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/

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
