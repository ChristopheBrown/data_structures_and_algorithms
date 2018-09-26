/*
 * P_node_int.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

#include "P_node_int.h"

P_node_int::P_node_int ( int num ) {
	data = num;
	next = NULL;
}

void P_node_int::print() {
	printf("%d\n",data);
}

