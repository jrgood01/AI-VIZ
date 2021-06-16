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
#include "../../../AI-VIZ/NeuralNet/transfer-Optimization-List.cpp"
#include "../../../AI-VIZ/NeuralNet/transfer-Functions.h"
#include "../../../AI-VIZ/NeuralNet/transfer-Functions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TransferFunctionTests {

	TEST_CLASS(testBuildOptimizationList)
	{

	public:

		TEST_METHOD(testOptimizationListAddsHead)
		{
			double(*testTransferFunctionArr[9])(double) = {
				&basicTransfer_1, &basicTransfer_1, &basicTransfer_1,
				&basicTransfer_2, &basicTransfer_2,
				&basicTransfer_3,&basicTransfer_3,&basicTransfer_3, &basicTransfer_3,
			};

			transferOptimizationList* generatedList = buildOptimizationList(9, testTransferFunctionArr);

			transferOptimizationListNode* block_1 = generatedList->getHead();
			transferOptimizationListNode* block_2 = generatedList->getHead()->nextNode;
			transferOptimizationListNode* block_3 = generatedList->getHead()->nextNode->nextNode;

			Assert::IsTrue(block_1->size == 3);
			Assert::IsTrue(block_2->size == 2);
			Assert::IsTrue(block_3->size == 4);

			Assert::IsTrue(block_1->transferFunction == &basicTransfer_1);
			Assert::IsTrue(block_2->transferFunction == &basicTransfer_2);
			Assert::IsTrue(block_3->transferFunction == &basicTransfer_3);
		}


	};
}

