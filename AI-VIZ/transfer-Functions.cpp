/*
This file will define the transfer functions that can be used in neurons. 
*/
#include <math.h>
#include "transfer-Functions.h"
#include "transfer-Optimization-List.h"
#define e 2.71828

double relu(double x) {
	if (x > 0) {
		return x;
	}
	else {
		return 0;
	}
}

double sigmoid(double x) {
	return 1 / (1 + pow(e, -x));
}

double step(double x) {
	if (x > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

transferOptimizationList* buildOptimizationList(int vector_size, double(**transfer_function)(double)) {
	int block_len = 1;
	transferOptimizationList* retOptimizationList = new transferOptimizationList;
	for (int i = 1; i < vector_size; i++) {
		if (transfer_function[i] != transfer_function[i - 1] || i == vector_size - 1) {
			if (i == vector_size - 1) block_len++;
			retOptimizationList->addNode(transfer_function[i - 1], block_len);
			block_len = 0;
		}

	    block_len++;
	}

	return retOptimizationList;
}

/// <summary>
/// This method applies a vector of transfer functions to a vector of inputs.
/// </summary>
/// <param name = "vector_size"> Size of the input vector to pass to the function</param>
/// <param name = "input_vector"> A pointer to the input vector</param>
/// <param name = "optimizationList"> A TransferOptimizationList object containing blocks of function pointers </param>
/// <returns> An array of doubles that is the result of the transfer function vector applied to the input vector.</returns>
/*
double* apply_transfer_function(int vector_size, double* input_vector,transferOptimizationList* optimizationList) {

}
*/