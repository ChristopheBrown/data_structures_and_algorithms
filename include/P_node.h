/*
 * P_node.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef P_NODE_H_
#define P_NODE_H_


namespace ece309 {
	
	class P_node {
	public:
		P_node * next;

		virtual void print()=0;

		virtual ~P_node(){};
	};

}

#endif /* P_NODE_H_ */
