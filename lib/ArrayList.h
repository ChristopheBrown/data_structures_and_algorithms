/*
 * ArrayList.h
 *
 *  Created on: Sep 10, 2018
 *      Author: Christophe's Book
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <stdlib.h>
#include <stdio.h>

//typedef char* String;

class ArrayList {
	public:
		char **string_list;
		char *head;

		int array_size;
		int empty_spaces;

	public:
//		ArrayList();
		ArrayList(int);
		void push_back(char[]);
		char* get(int);
		int length();
		char* remove_front();

		~ArrayList();
};


#endif /* ARRAYLIST_H_ */
