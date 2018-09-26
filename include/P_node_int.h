/*
 * P_node_int.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */
#include "P_node.h"

#ifndef P_NODE_INT_H_
#define P_NODE_INT_H_

class P_node_int : public P_node {
public:
	int data;

	P_node_int (int num);

public:
	void print();
	~P_node_int() {};
};



#endif /* P_NODE_INT_H_ */
