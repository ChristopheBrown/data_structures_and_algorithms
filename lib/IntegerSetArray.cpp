/*
 * IntegerSetArray.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Christophe's Book
 */

#include "IntegerSetArray.h"
using namesapce ece309;
#define EMPTY -1


IntegerSetArray::IntegerSetArray(int htsize):IntegerSet(htsize) {
	array = new int[size];
	int iterator=0;
	while (iterator < size)
		array[iterator++] = EMPTY;
}

bool IntegerSetArray::insert (int data) {
	for (int iterator=0; iterator < size; iterator++)
		if (array[iterator] == EMPTY)
		{
			array[iterator] = data;
			return true;
		}
	return false;
}

bool IntegerSetArray::search (int data) const {
	for (int iterator=0; iterator < size; iterator++)
		if (array[iterator] == data)
		{
			return true;
		}
	return false;
}

void IntegerSetArray::remove (int data) {
	for (int iterator=0; iterator < size; iterator++)
		if (array[iterator] == data)
			array[iterator] = EMPTY;
}


