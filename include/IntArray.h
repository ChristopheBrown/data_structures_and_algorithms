/*
 * IntArray.h
 *
 *  Created on: Oct 10, 2018
 *      Author: Christophe's Book
 */

#ifndef INTARRAY_H_
#define INTARRAY_H_

#include <stdio.h>
#include <stdlib.h>

namespace ece309 {
	class IntArray {
	private:
		int * array;
		int length;
	public:
		IntArray(const char* str);
		IntArray(int size, int val);
		int& operator[](int index);
		IntArray& operator+=(const IntArray &rhs);
		IntArray operator+(const IntArray &rhs) const;
		IntArray operator-(const IntArray &rhs) const;
		IntArray operator*(int x) const;
		IntArray operator/(int x) const;
		IntArray operator<<(int count) const;
		operator char*() const;
		operator int() const;

	   ~IntArray() {
		 delete [] array;
	   }

	   IntArray(const IntArray &copy) {
		 length = copy.length;
		 array = new int[length];
		 for(int i=0; i<length; i++)
		   array[i] = copy.array[i];
	   }

	   IntArray& operator=(const IntArray &rhs) {
		 if(this == &rhs) return *this;
		 printf("Running operator=!\n");
		 delete [] array;
		 length = rhs.length;
		array = new int[length];
		for(int i=0; i<length; i++)
		   array[i] = rhs.array[i];
		return *this; // reference to this object
	   }

	  void rand(int M=100) {
		for(int i=0; i<length; i++)
		  array[i] = ::rand() % M;
	  }

	   void set(int index, int val) {
		 array[index] = val;
	   }

	   int get(int index) {
		   return array[index];
	   }

		int getLength() { return length; }
	};

}

#endif /* INTARRAY_H_ */

