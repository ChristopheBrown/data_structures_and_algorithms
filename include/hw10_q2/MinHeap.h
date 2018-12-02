/*
 * MinHeap.h
 *
 *  Created on: Nov 20, 2018
 *      Author: Christophe's Book
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


namespace ece309 {
  
  class MinHeap {
  private:
    int *heapArray;    // this is the maxheap
    int heapArraySize; // size of the array
    int nextIndex;     // location of next free array entry

  protected:
    void percolate_up(int);
    void percolate_down(int, int);

  public:
    MinHeap(int size = 100) : heapArraySize(size) {
      heapArray = new int[size];
      for (int i = 0; i < size; i++)
        heapArray[i] = 0;
      nextIndex = 0;
    }

    void print() {
      for (int i = 0; i < nextIndex; i++) {
        printf("%d ", heapArray[i]);
      }
      printf("\n");
    }

    int* operator[](int);
    int getHeapArraySize();

    bool insert(int);
    bool remove(int &); // remove the max value
    bool isEmpty();
  };

}

#endif /* MINHEAP_H_ */
