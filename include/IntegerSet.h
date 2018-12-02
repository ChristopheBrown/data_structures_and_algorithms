/*
 * IntergetSet.h
 *
 *  Created on: Oct 16, 2018
 *      Author: Christophe's Book
 */


#ifndef INTEGERSET_H
#define INTEGERSET_H

#include "List.h"
#include "Math.h"

#define ENDOFSET -3

namespace ece309 {

	// IntegerSet abstract base class to demonstrate hash table concepts
	class IntegerSet {
	protected:
	   int size;
	   int hash(int key) const { return (key * 997) % size;}
	public:
	   IntegerSet(int htsize):size(htsize+1) {}
	   virtual bool insert(int) = 0;
	   virtual bool search(int) const = 0;
	   virtual void remove(int) = 0;
	};

	// Hash Table with Linear Probing
	class IntegerSetHT : public IntegerSet {
	protected:
	  int *table;
	  int probeDistance;
	  const int empty_since_start = -2;
	  const int empty_after_removal = -1;

			  int count_collision;
			  int count_failure;



	public:
	   IntegerSetHT(int htsize);
	   virtual bool insert(int) override;
	   virtual bool search(int) const override;
	   virtual void remove(int) override;

			   int collisions();
			   int failures();
			  class iterator {
			  protected:
				  int * data;

			  public:
				  iterator (int * list_start)
				  {
					   data = list_start;
				  }
				  void increment();
				  bool end();
				  int getInt();
				  int getInt(int*);
			  };

			  iterator begin () { return iterator(table); }
	};

	// Hash Table with Chaining
	class IntegerSetHTChain : public IntegerSet {
	protected:
	  List *table;
	public:
	   IntegerSetHTChain(int htsize);
	   virtual bool insert(int) override;
	   virtual bool search(int) const override;
	   virtual void remove(int) override;
	};
	
}
#endif //INTEGERSET_H
