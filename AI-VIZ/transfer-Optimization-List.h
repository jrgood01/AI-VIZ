#pragma once
/// <summary>
///  This struct represents a node within the transfer optimization linked list.
/// </summary>

struct transferOptimizationListNode {
	/// <value> Pointer to the transfer function at this location </value>
	double(*transferFunction)(double);
	/// <value> The number of times that this transfer function is repeated </value>
	int size;
	/// <value> The next node </value>
	transferOptimizationListNode* nextNode;
};

class transferOptimizationList {
private:
	transferOptimizationListNode* head;
	transferOptimizationListNode* tailNode;
public:
	transferOptimizationList();

	~transferOptimizationList();

	void clear();

	void addNode(double(*transferFunction)(double x), int blockSize);

	transferOptimizationListNode* getHead();

};