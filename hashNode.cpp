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
	valuesSize = 101;
	currSize = 0;
	values = new string[valuesSize];
}

hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	values = new string[valuesSize];
	values[0] = v;
	currSize = 1;
}

void hashNode::addValue(string v){

	values[currSize] = v;
	currSize++;


	if(currSize >= valuesSize){
		dblArray();
	}

	cout << "hey you added a values" << endl;

}

void hashNode::dblArray(){
	string * tmp = new string[valuesSize *2];
	for(int i = 0; i < valuesSize; i++){
		tmp[i] = values[i];
	}
	values = tmp;
	valuesSize *= 2;
}

string hashNode::getRandValue(){
	if(currSize == 0){
		return "";
	}else{
		return values[(rand() % currSize)];
	}
}







