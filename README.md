# Christophe Brown - Data Structures and Algorithms - ECE 498 NC State University - Fall 2018

Repo includes c++ implementations of various data structures. (i.e linked lists, hashmaps, and graphs)

*ASSIGNMENT 2*
* Login to Github
* Create a new repo
* Clone Dr. Tuck's repo files into the directory and add him as a shared memeber
* Perform Homework duties and upload code to the repo
* Profit 

[![Build Status](https://travis-ci.org/jamesmtuck/ece309-fall18-unityid.svg?branch=master)](https://travis-ci.org/CBreezyNCSU/ece309-fall18-cjbrown8)


*ADDIGNMENT 4*
PList allows the user to implement a Linked List that can store strings, integers, and double values. 
The PList offers members:
 * head node
* iterator class {} with void increment(), P_node &getNode(), bool end()
* void append (int);
* void append (double);
* void append (const char*);
* void remove(iterator &it);


*ADDIGNMEN 5*
Offers IntArray and IntegerSetArray support:
IntArray is a class to explore the functionily of overriding methods that are created by the compiler. Of which include:
*	IntArray& operator+=(const IntArray &rhs);
*	IntArray operator+(const IntArray &rhs) const;
*	IntArray operator-(const IntArray &rhs) const;
*	IntArray operator*(int x) const;
*	IntArray operator/(int x) const;
*	ItArray operator<<(int count) const;
*	operator char*() const;
*	operator int() const;

*ASSIGNMENT 6*
Includes functionality for IntegerSet as well as IntegerSetHT for hash table (with iterator) creation
