/*
 * ArrayList.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: Christophe's Book
 */
#include "ArrayList.h"

using namesapce ece309::ArrayList;

#ifndef NULL
#define NULL 0
#endif

ArrayList::ArrayList(int size=1) {
	array_size = empty_spaces = size;
	string_list = new char*[size];
	for (int i=0;i<size;i++) string_list[i]=NULL;
	head = string_list[0];
}

char* ArrayList::get(int index) {
	if (index > (array_size-empty_spaces)) return string_list[array_size-empty_spaces-1];
	if (index < 0) return string_list[0];
	return string_list[index];
}

char* ArrayList::remove_front() {
	char* old_head = string_list[0];
	string_list+=1;
	return old_head;
}

int ArrayList::length() {
	return array_size-empty_spaces;
}

void ArrayList::push_back(char str[]) {
	if (empty_spaces==0)
	{
		printf("Array is full! Allocating new space..\n");
		ArrayList *bigger_array = new ArrayList(array_size*2);
		int i;
		for (i=0;i<array_size;i++)
		{
			bigger_array->string_list[i] = string_list[i];
			bigger_array->empty_spaces--;
		}
		delete string_list;
		string_list = bigger_array->string_list;
		head = string_list[0];
		array_size = bigger_array->array_size;
		empty_spaces = bigger_array->empty_spaces;
//		delete bigger_array;
	}
	int index_of_next_empty_element=0;
	int &index = index_of_next_empty_element;
	for (index=0;index<array_size;index++)
	{
		if (string_list[index] == NULL) break;
	}
	string_list[index_of_next_empty_element] = str;

	empty_spaces--;
}

ArrayList::~ArrayList() {

	delete string_list;
}
