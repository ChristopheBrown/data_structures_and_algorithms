#include "EdgeList.h"
#include <stdio.h>

EdgeList::EdgeList() {
  // initialize empty list
  head = NULL;
  tail = NULL;
}

void EdgeList::append(Edge a) {
  ListNode *node = new ListNode(a, NULL, tail);
  if (head == NULL) {
    // list is empty
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void EdgeList::insertAfter(EdgeList::iterator it, Edge item) {
  if (head == NULL || it.node == NULL) { // NULL iterator means insert at head
    ListNode *node = new ListNode(item, head); // next=head, prev=NULL
    if (head == NULL)                          // same as zyBook
      head = tail = node;
    else { // if inserting before head, it.node==NULL
      head->prev = node;
      head = node;
    }
  } else if (it.node == tail) {
    ListNode *node = new ListNode(item, NULL, tail); // next=NULL, prev=old tail
    tail->next = node;
    tail = node;
  } else {
    ListNode *node = new ListNode(item, it.node->next, it.node);
    it.node->next = node;
    node->next->prev = node;
  }
}

void EdgeList::erase(EdgeList::iterator it) {
  ListNode *succ = it.node->next; // successor node
  ListNode *pred = it.node->prev; // predecessor node

  if (succ != NULL)
    succ->prev = pred;
  if (pred != NULL)
    pred->next = succ;

  if (it.node == head)
    head = succ; // head is following node
  if (it.node == tail)
    tail = pred; // tail is previous node

  delete it
      .node; // delete the node; not shown in zyBook, but necessary in C/C++
  // iterator is now invalid, caller should not use it again
}

void EdgeList::insertInOrder(Edge e) {
  iterator it = begin(), prev;
  while (!it.end()) {
    if (it.getEdge().weight > e.weight) {
      break;
    }
    prev = it;
    it.increment();
  }
  insertAfter(prev, e);
}
