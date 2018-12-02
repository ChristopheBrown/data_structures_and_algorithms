/*
 * P_node_double.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

#include "P_node_double.h"
using namesapce ece309;
P_node_double::P_node_double(double num){
	data = num;
	next = NULL;
}

void P_node_double::print() {
	printf("%lf\n",data);
}
