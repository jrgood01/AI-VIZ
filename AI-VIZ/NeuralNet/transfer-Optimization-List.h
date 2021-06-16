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