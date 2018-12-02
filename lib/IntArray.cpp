/*
 * IntArray.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Christophe's Book
 */

#include <string.h>
#include "IntArray.h"

using namesapce ece309;

IntArray::IntArray(const char* str) {
	length = strlen(str);
	array = new int[length];

	for (int iterator=0;iterator<length;iterator++)
		array[iterator]=str[iterator];
}

IntArray::IntArray(int size,int val=0) {
	length = size;
	array = new int[size];

	for (int iterator=0;iterator<length;iterator++)
		array[iterator] = val;
}

int& IntArray::operator[] (int index) {
	return array[index];
}

IntArray& IntArray::operator+=(const IntArray &rhs) {
	for (int iterator=0;iterator<length;iterator++)
	{
		int num = rhs.array[iterator];
		array[iterator] += num;
	}

	return *this;
}

IntArray IntArray::operator+(const IntArray &rhs) const{
	IntArray new_array(this->length,0);

	for (int iterator=0;iterator<this->length;iterator++)
		new_array[iterator] = array[iterator] + rhs.array[iterator];

	return new_array;
}

IntArray IntArray::operator-(const IntArray &rhs) const{
	IntArray new_array(this->length,0);

	for (int iterator=0;iterator<this->length;iterator++)
	{
		new_array[iterator] = this->array[iterator] - rhs.array[iterator];
	}


	return new_array;
}

IntArray IntArray::operator*(int x) const{
	IntArray new_array(this->length,0);

	for (int iterator=0;iterator<this->length;iterator++)
		new_array[iterator] = this->array[iterator] * x;

	return new_array;
}

IntArray IntArray::operator/(int x) const{
	IntArray new_array(this->length,0);

	for (int iterator=0;iterator<this->length;iterator++)
		new_array[iterator] = this->array[iterator] / x;

	return new_array;
}

IntArray IntArray::operator<<(int x) const{
	IntArray new_array(this->length,0);
	int iterator;

	for (int rotations=0;rotations<x;rotations++){
		for (iterator=0;iterator<this->length;iterator++)
			new_array[iterator+1] = this->array[iterator];

	new_array[0]=this->array[length-1];
	}

	return new_array;
}

IntArray::operator char*() const {
	char * str = new char[this->length+1];
	int iterator;

	for (iterator=0;iterator<this->length;iterator++)
	{
		int array_index_value = this->array[iterator];
		if (array_index_value > 255 || array_index_value < 0)
			str[iterator] = ' ';
		else
			str[iterator] = (char) this->array[iterator];
	}
	str[iterator]='\0';

	return str;
}

IntArray::operator int() const {
	int sum=0;
	double average=0.0;

	for (int iterator=0;iterator<this->length;iterator++)
		sum+=this->array[iterator];

	average = sum / this->length;
	return average;
}

