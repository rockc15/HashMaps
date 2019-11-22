/*
 * hashNode.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: casey
 */



#include "hashNode.hpp"


hashNode::hashNode(){
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}

hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 10;
	currSize = 0;
	values = new string[valuesSize];
}

hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 10;
	values = new string[valuesSize];
	values[0] = v;
	currSize = 1;
}

/*
 * consumes: string v represing a values
 *
 * add the v to the values array
 */
void hashNode::addValue(string v){
	if(valuesSize == currSize){
		dblArray();
	}

	values[currSize] = v;
	currSize++;



}

/*
 * makes a new array that is twice the size of the values array
 * then copies all the values in the new array and sets the
 * values array to the new array
 */
void hashNode::dblArray(){
	string * tmp = new string[valuesSize *2];
	for(int i = 0; i < valuesSize; i++){
		tmp[i] = values[i];
	}
	values = tmp;
	valuesSize *= 2;
}


/*
 * gets a random values from the nodes value array
 */
string hashNode::getRandValue(){
	if(currSize == 0){
		return "";
	}else{
		return values[(rand() % currSize)];
	}
}







