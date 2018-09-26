/*
 * P_node_string.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

#include "P_node_string.h"

P_node_string::P_node_string(const char* string) {
	data = string;
	next = NULL;
}

void P_node_string::print() {
	printf("%s\n",data);
}

