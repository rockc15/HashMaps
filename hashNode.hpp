/*
 * hashNode.hpp
 *
 *  Created on: Nov 19, 2019
 *      Author: casey
 */



#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_
#include <string>
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

class hashNode {
	friend class hashMap;
	string keyword;   // this is used as the key � each key is only inserted once!
	string *values;   // the dynamically allocated array (not linked list!) of words that follow the key in the Dr. Seuss text.  If this set of words gets to be larger than the valuesSize of the array, then you must re-allocate the array double in size and copy over all the old values
	int valuesSize;  // the size of the values array
	int currSize;  // the number of words in the values array so far
public:
	//constructor-initializes keyword to �� , valuesSize to 0,
	//and currSize to 0 and values to NULL
	hashNode();

	// initializes keyword to s, the valuesSize to 100 (or whatever you
	//like for starting), the currSize to 0, and the values to be a
	//dynamically allocated array of valuesSize
	hashNode(string s);

	// in addition, puts a value in the values array and initializes currSize to 1
	hashNode(string s, string v);

	// adds a new value to the end of the values array, increases currSize,
	//checks to make sure there�s more space, and, if not, calls dblArray()
	void addValue(string v);

	//creates a new array, double the length, and copies over the values.
	//Sets the values array to be the newly allocated array.
	void dblArray();

	// returns a random string from the values array.  If there�s no values
	//in the value array, then it returns an empty string.
	string getRandValue();
};

#endif
