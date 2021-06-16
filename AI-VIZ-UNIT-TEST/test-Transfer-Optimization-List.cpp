#include "pch.h"
#include "CppUnitTest.h"
#include "../AI-VIZ/transfer-Optimization-List.h"

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
