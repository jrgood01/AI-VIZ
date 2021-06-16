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

#include "pch.h"
#include "CppUnitTest.h"
#include "../../../AI-VIZ/NeuralNet/transfer-Optimization-List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TransferFunctionTests
{

	TEST_CLASS(testTransferOptimizationList)
	{
	public:

		TEST_METHOD(testOptimizationListAddsHead)
		{
			transferOptimizationList optimizationList;
			optimizationList.addNode(basicTransfer_1, 2);
			transferOptimizationListNode* head = optimizationList.getHead();
			Assert::IsTrue(head->transferFunction == &basicTransfer_1);
			Assert::IsTrue(head->size == 2);
		}

		TEST_METHOD(testOptimizationListClearsHead)
		{
			transferOptimizationList optimizationList;
			optimizationList.addNode(basicTransfer_1, 2);
			transferOptimizationListNode* head = optimizationList.getHead();
			optimizationList.clear();

			Assert::IsFalse(head->transferFunction == &basicTransfer_1);
		}

		TEST_METHOD(testOptimizationListAddsMultiple)
		{
			transferOptimizationList optimizationList;
			optimizationList.addNode(basicTransfer_1, 1);
			optimizationList.addNode(basicTransfer_2, 2);
			optimizationList.addNode(basicTransfer_3, 3);
			transferOptimizationListNode* head = optimizationList.getHead();

			Assert::IsTrue(head->transferFunction == &basicTransfer_1);
			Assert::IsTrue(head->nextNode->transferFunction == &basicTransfer_2);
			Assert::IsTrue(head->nextNode->nextNode->transferFunction == &basicTransfer_3);

			Assert::IsTrue(head->size == 1);
			Assert::IsTrue(head->nextNode->size == 2);
			Assert::IsTrue(head->nextNode->nextNode->size == 3);
		}

	};
}
