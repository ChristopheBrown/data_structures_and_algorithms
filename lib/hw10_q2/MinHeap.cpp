/*
 * MinHeap.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Christophe's Book
 */

#include "MinHeap.h"

int* MinHeap::operator[](int i) {
	if (i > heapArraySize || i < 0) return 0;
	return heapArray+i;
}

int MinHeap::getHeapArraySize() {
	return heapArraySize;
}


void MinHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index] < heapArray[parent_index]) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[parent_index];
      heapArray[parent_index] = tmp;
      index = parent_index;
    } else
      return;
  }
}

void MinHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index];
  while (child_index < size) {
    int min_val = val;
    int max_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i] < min_val) {
        min_val = heapArray[i];
        max_index = i;
      }
    }
    if (min_val == val)
      return;
    heapArray[index] = min_val;
    heapArray[max_index] = val;
    index = max_index;
    child_index = index * 2 + 1;
  }
}

bool MinHeap::insert(int data) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex] = data;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool MinHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

bool MinHeap::isEmpty() {
	 if (nextIndex <= 0) return true;
	 return false;
}

//int main() {
//  MinHeap heap;
//
//  int gold = -1, silver = -1, bronze = -1;
//  heap.topthree(gold, silver, bronze);
//  printf("topthree: %d %d %d\n", gold, silver, bronze);
//
//  heap.insert(45);
//  heap.print();
//
//  heap.topthree(gold, silver, bronze);
//  printf("topthree: %d %d %d\n", gold, silver, bronze);
//
//  heap.insert(100);
//  heap.print();
//
//  heap.topthree(gold, silver, bronze);
//  printf("topthree: %d %d %d\n", gold, silver, bronze);
//
//  heap.insert(83);
//  heap.insert(15);
//
//  heap.topthree(gold, silver, bronze);
//  printf("topthree: %d %d %d\n", gold, silver, bronze);
//
//  heap.insert(5);
//  heap.insert(50);
//  heap.insert(82);
//  heap.print();
//
//  heap.topthree(gold, silver, bronze);
//  printf("topthree: %d %d %d\n", gold, silver, bronze);
//
//  /*
//    int ref;
//    heap.remove(ref);
//    heap.print();
//    for (int i = 0; i < 100; i++)
//      heap.insert(rand() % 1000);
//    for (int i = 0; i < 20; i++)
//      heap.remove(ref);
//  */
//  heap.print();
//
//  return 0;
//}

