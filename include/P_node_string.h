/*
 * P_node_string.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */
#include "P_node.h"

#ifndef P_NODE_STRING_H_
#define P_NODE_STRING_H_


namespace ece309 {
	
	class P_node_string : public P_node {
	public:
		const char* data;

		P_node_string ( const char* string );

	public:
		void print();
		~P_node_string() {};
	};
}


#endif /* P_NODE_STRING_H_ */
