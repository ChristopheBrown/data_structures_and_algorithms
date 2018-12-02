/*
 * Plist.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

//#include "P_node.h"
#include "P_node_int.h"
#include "P_node_double.h"
#include "P_node_string.h"


#ifndef PLIST_H_
#define PLIST_H_


namespace ece309 {
	
	class PList {
	public:
		P_node * head;

		PList ();
		PList (int);
		PList (double);
		PList (const char*);

	public:
		class iterator {
		private:
			P_node * node;

		public:
			iterator(P_node *n=NULL) { node = n; }
			P_node &getNode() { return *node; } // P_node contains nothing, just a type. ->don't do this?
	//		void begin() { node = head; }
			bool end() { return node == NULL; }
			void increment(int n=1) { for(int i=0;i<n;i++) node = node->next; }
	//		void decrement() { P_node * index=node; begin(); while(node->next != index) increment(); }

			friend class PList;
		};


	public:
		iterator begin() { iterator it = iterator(head); return it; }
		void append (int);
		void append (double);
		void append (const char*);

		void remove(iterator &it);

		~PList();
	};
}


#endif /* PLIST_H_ */
