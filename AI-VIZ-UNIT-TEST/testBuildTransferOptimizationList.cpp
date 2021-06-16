#include "pch.h"
#include "CppUnitTest.h"
#include "../AI-VIZ/transfer-Optimization-List.h"
#include "../AI-VIZ/transfer-Optimization-List.cpp"
#include "../AI-VIZ/transfer-Functions.h"
#include "../AI-VIZ/transfer-Functions.cpp"

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

