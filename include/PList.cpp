/*
 * PList.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Christophe's Book
 */

#include <stdio.h>
#include <stdlib.h>

#include "PList.h"

PList::PList() {
	head = new P_node_int(0);
}

PList::PList(int num) {
	head = new P_node_int(num);
}

PList::PList(double num) {
	head = new P_node_double(num);
}

PList::PList(const char * string) {
	head = new P_node_string(string);
}

void PList::append(int num) {
	P_node * node_indexer = head;
	P_node_int * new_int_node = new P_node_int(num);

	while (node_indexer->next != NULL)
	{
		node_indexer = node_indexer->next;
	}

	node_indexer->next = new_int_node;
}

void PList::append(double num) {
	P_node * node_indexer = head;
	P_node_double * new_double_node = new P_node_double(num);

	while (node_indexer->next != NULL)
	{
		node_indexer = node_indexer->next;
	}

	node_indexer->next = new_double_node;
}

void PList::append(const char* string) {
	P_node * node_indexer = head;
	P_node_string * new_stirng_node = new P_node_string(string);

	while (node_indexer->next != NULL)
	{
		node_indexer = node_indexer->next;
	}

	node_indexer->next = new_stirng_node;
}

void PList::remove(iterator& it) { // counts beginning at zero
	P_node * successor = it.node->next;

	if (head == NULL) return; // Empty List


	if (it.node == head) // head node (works for list of size 1)
	{
		head = head->next;
		delete it.node;
		it.node = head;
		return;
	}

	if (it.node->next == NULL) // tail node; sets iterator back to head when deleted.
	{
		printf("removing..\n");
		delete it.node;
		it.node=NULL;
		return;
	}

	if (successor != NULL) // middle node
	{
		P_node * goodbye_node = it.node;
		it.node = successor;
		delete goodbye_node;
		return;
	}
}

PList::~PList() {
	iterator it = begin();
	while (!it.end())
	{
		P_node * node = it.node;
		it.increment();
		delete node;
	}

}

