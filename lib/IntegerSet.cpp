/*
 * IntegerSet.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: Christophe's Book
 */

#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
	count_collision = 0;
	count_failure = 0;

  probeDistance = 10;
   table = new int[size+1];
   int i;
   for(i=0; i<size; i++)
       { table[i] = empty_since_start; } // -1 means empty
   table[size] = ENDOFSET;
}

bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;

  bool collision_occurred = false;

  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   } else if (!collision_occurred) {
	   count_collision++;
	   collision_occurred = ~collision_occurred;
   }
   index = (index+1) % size;
  }
  // otherwise give up
  count_failure++;
   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

IntegerSetHTChain::IntegerSetHTChain(int htsize)
:IntegerSet(htsize)
{
  table = new List[size];
}

bool IntegerSetHTChain::insert(int data)
{
  List::iterator it;
  table[hash(data)].insertAfter(it,data);
  return true;
}

bool IntegerSetHTChain::search(int data) const
{
   List::iterator it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data)
        return true;
     it.increment();
   }
   return false;
}

void IntegerSetHTChain::remove(int data)
{
   List::iterator prev,it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data) {
        table[hash(data)].removeAfter(prev);
        return;
     }
     prev = it;
     it.increment();
   }
}

int IntegerSetHT::collisions()
{
	return count_collision;
}

int IntegerSetHT::failures()
{
	return count_failure;
}

bool IntegerSetHT::iterator::end() {
	if (getInt() == ENDOFSET) return true;
	return false;
}

void IntegerSetHT::iterator::increment() {
	if (end()) return;
	do { data++; }
	while (*data<0 && !end());
}

int IntegerSetHT::iterator::getInt() {
	if (*data >= 0 || *data == ENDOFSET) return *data;
	return getInt(data+1);
}

int IntegerSetHT::iterator::getInt(int * next) {
	if (*next >= 0 || *next == ENDOFSET) return *next;
	else return getInt(next+1);
}



//int main()
//{
//  IntegerSetHTChain set(1000);
//
//  set.insert(100);
//  set.insert(100);
//  if(set.search(100))
//    printf("Found 100!");
//  else
//    printf("Didn't find 100!");
//
//    set.remove(100);
//    if(set.search(100))
//      printf("Found 100!");
//    else
//      printf("Didn't find 100!");
//
//      set.remove(100);
//      if(set.search(100))
//        printf("Found 100!");
//      else
//        printf("Didn't find 100!");
//
//
//  return 0;
//}


