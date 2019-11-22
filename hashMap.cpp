/*
 * hashMap.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: casey
 */



#include "hashMap.hpp"

hashMap::hashMap(bool hash1, bool coll1){
	mapSize =   103;

	map = new hashNode*[mapSize];

	for(int i = 0; i < mapSize;i++){
		map[i] = NULL;
	}

	first = "";
	numKeys = 0;
	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;

}

void hashMap::addKeyValue(string k, string v){
	cout << "numkeys " << numKeys << " map size " << mapSize << endl;
	double nk = numKeys, ms = mapSize;
	if((nk / ms) > .70){
		reHash();

	}

	int index = getIndex(k);


	if(map[index] == NULL){

		map[index] = new hashNode(k,v);
		numKeys++;
	}
	else if(map[index]->keyword == k){

		map[index]->addValue(v);
		numKeys++;

	} else{
		if(c1){

			map[collHash1(index,k)] = new hashNode(k,v);
			numKeys++;
		}else {
			map[collHash2(index,k)] = new hashNode(k,v);
			numKeys++;
		}
	}

}


int hashMap::getIndex(string k){
	int index;

	if(h1){
		index = calcHash1(k);

	}else {
		index = calcHash2(k);
	}
	return index;
}

int hashMap::calcHash1(string k){
	int sum = 0;
	int finalIndex;

	for(int i = 0; i < k.length(); i++){
		sum += k[i];
	}
	if(sum < 0)
		sum *= -1;


	finalIndex = sum % mapSize;

	return finalIndex;
}

int hashMap::calcHash2(string k){
	int len = k.length();
	int h = 0;

	for(int i = len -1; i > 0; i--){
		h = (h*19 + (int)k[i]) % mapSize;
	}
	if(h < 0)
		h *= -1;

	return h;
}

void hashMap::getClosestPrime(){
	int doubleArr = mapSize *2;
	int primes[] = {101, 211, 431, 863, 1733, 3467,6997, 13999 ,  28057};
	int i = 0;
	while(doubleArr > primes[i]){
		i++;
	}
	mapSize = primes[i];
}

void hashMap::reHash(){
	int lastMapSize = mapSize;
	getClosestPrime();

	hashNode ** newMap = new hashNode*[mapSize];
	for(int i = 0; i < mapSize; i++){
		newMap[i] = NULL;
	}


	for(int i = 0; i < lastMapSize; i++){
		if(map[i] != NULL){
			newMap[getIndex(map[i]->keyword)] = map[i];
		}
	}


	map = newMap;

}


//linear probling
int hashMap::collHash1(int index, string k){
	//int index = getIndex(k);

	if(map[index] == NULL){
		return index;
	}else {
		while(map[index] != NULL){
			if(map[index]->keyword == k){
				map[index]->addValue(k);
			}
			index++;
			collisionct2++;
			if(index == mapSize){
				index = 0;
			}
		}
		return index;
	}

}

//quadratic probing
int hashMap::collHash2(int i, string k){
	int factor = 1;
	bool flag = true;
	while(flag){

	}
	return 0;
}

int hashMap::findKey(string k){
	int index = getIndex(k);

	if(map[index] == NULL){
		return -1;
	}

	if(map[index]->keyword == k){
		return index;
	}

	if(c1){
//		while(map[index] != NULL && map[index]->keyword != k){
//			index++;
//			if(index > mapSize){
//				index = 0;
//			}
//		}
//		return index;
		return collHash1(index, k);
	}else{
		//quadratic probling
	}


	return 0;
}

void hashMap::printMap(){
	for(int i = 0 ; i < mapSize; i++){
		if(map[i] != NULL){
			cout << map[i]->keyword<< " ";
		}
	}
	cout << endl;
}












