/*
 * P_node_double.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */
#include "P_node.h"

#ifndef P_NODE_DOUBLE_H_
#define P_NODE_DOUBLE_H_

namespace ece309 {

	class P_node_double : public P_node {
	public:
		double data;

		P_node_double ( double num );

	public:
		void print();
		~P_node_double() {};
	};

}

#endif /* P_NODE_DOUBLE_H_ */
