/*
 * LinkedList.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: Christophe's Book
 */
#include <stdio.h>

class ListNode
{
public:
	const char * message;
	ListNode * next;

	ListNode( const char* str=0 )
	{
		message = str;
		next = 0;
	}
	~ListNode()
	{
//		printf("Saying goodbye to node \"%s\"\n",this->message);
	}
};

class LinkedList
{
public:
	ListNode * head;

	LinkedList( const char* str)
	{
		head = new ListNode(str);
	}

	ListNode get(int depth_count)
	{
		int i;
		ListNode * node = head;

		for (i=0; (i<depth_count) && (node->next != 0) ;i++)
		{
			node = node->next;
		}
		return *node;
	}

	void push_back( const char* str)
	{
		ListNode * node = head;

		while (node->next != 0)
		{
			node = node->next;
		}

		ListNode * new_node = new ListNode(str);
		node->next = new_node;

		return;
	}

	int length(void)
	{
		if (head==0) return 0;

		int count=0;
		ListNode * node = head;

		while (node->next != 0)
		{
			node = node->next;
			count++;
		}
		return ++count;
	}

	ListNode remove_front()
	{
		ListNode return_copy = *head;
		ListNode *node_to_delete = head;
		head = head->next;
		delete node_to_delete;

		return return_copy;
	}


	~LinkedList()
	{
		ListNode *node_to_delete=head;
		ListNode *next_to_delete;
		while (node_to_delete != 0)
		{
			next_to_delete = node_to_delete->next;
			delete node_to_delete;
			node_to_delete = next_to_delete;
		}
	}

};
