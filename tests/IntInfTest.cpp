/*
 * main.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Christophe's Book
 */

#include <stdlib.h>
#include <stdio.h>

#include "IntInf.h"

int main (void) {
	IntInf x(50);
	IntInf y(10);

	printf("X: %d\n",x.getInteger());
	printf("Y: %d\n",y.getInteger());

	IntInf z; // defaults to indeterminant until you set it

	printf("Let Z be the result of various operations using X and Y.\n");

	z = x + 2;
	printf("Sum of IntInf object and integer: %d\n",z.getInteger());
	z = x + y;
	printf("Sum of two IntInf objects: %d\n",z.getInteger());
	z = x - 2;
	printf("Difference of IntInf object and integer: %d\n",z.getInteger());
	z = x - y;
	printf("Difference of two IntInf objects: %d\n",z.getInteger());
	z = x * 2;
	printf("Product of IntInf object and integer: %d\n",z.getInteger());
	z = x * y;
	printf("Product of two IntInf objects: %d\n",z.getInteger());
	z = x / 2;
	printf("Quotient of IntInf object and integer: %d\n",z.getInteger());
	z = x / y;
	printf("Quotient of two IntInf objects: %d\n",z.getInteger());

	printf("Greater than > works with object and number: %s\n",x>1?"TRUE" : "FALSE");
	printf("Less than < works with object and number: %s\n",x<100?"TRUE" : "FALSE");

	printf("Greater than > works with two objects: %s\n",x>y?"TRUE" : "FALSE");
	printf("Less than < works with two objects: %s\n",y<x?"TRUE" : "FALSE");

	IntInf copyOfX;
	copyOfX = x;
	printf("Comparison == works with two objects: %s\n",copyOfX==x? "TRUE" : "FALSE");

	printf("Let operationResult be the result of various operations using PosInf and NegInf.\n");

	IntInf positiveInfinity(true); // pos infinity
	IntInf negativeInfinity(false); // neg infinity

	IntInf operationResult;

	operationResult = positiveInfinity + 2;
	printf("Sum of Infinity and integer works: %s\n",operationResult.getType() == POSITIVE_INFINTY ? "TRUE" : "FALSE");

	operationResult = positiveInfinity - 2;
	printf("Difference of Infinity and integer works: %s\n",operationResult.getType() == POSITIVE_INFINTY ? "TRUE" : "FALSE");

	operationResult = positiveInfinity * (-2);
	printf("Product of Infinity and negative integer works: %s\n",operationResult.getType() == NEGATIVE_INFINITY ? "TRUE" : "FALSE");

	operationResult = negativeInfinity * 2;
	printf("Quotient of Negative Infinity and integer works: %s\n",operationResult.getType() == NEGATIVE_INFINITY ? "TRUE" : "FALSE");

	operationResult = positiveInfinity / 0;
	printf("Quotient of Infinity and zero works: %s\n",operationResult.getType() == INDETERMINANT ? "TRUE" : "FALSE");

	printf("Positive infinity == (-1)*Negative infinity: %s\n", (positiveInfinity == (negativeInfinity * (-1))) == false ? "TRUE" : "FALSE");

	operationResult = positiveInfinity - positiveInfinity;
	printf("Positive infinity - Positive infinity = Positive infinity: %s\n",operationResult.getType() == POSITIVE_INFINTY ? "TRUE" : "FALSE");

	operationResult = positiveInfinity * 0;
	printf("Positive infinity * 0 = 0: %s\n",(operationResult.getInteger() == 0) && operationResult.getType() == INTEGER ? "TRUE" : "FALSE");

	printf("Comparison among infinities is false: %s\n", (positiveInfinity == negativeInfinity) == false ? "TRUE" : "FALSE");

	printf("Positive infinity greater than Positive infinity is false: %s\n", (positiveInfinity > positiveInfinity) == false ? "TRUE" : "FALSE");

	printf("Negative infinity less than Negative infinity is false: %s\n", (negativeInfinity < negativeInfinity) == false ? "TRUE" : "FALSE");

	return 0;
}


