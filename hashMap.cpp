/*
 * hashMap.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: casey
 */



#include "hashMap.hpp"

//constructor for the hashmap Class
hashMap::hashMap(bool hash1, bool coll1){
	mapSize =   101;

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

/*cosnumes: a string k that represents the key
 * 			a string v that represents the values
 *
 * if the number keys is 70% of the mapSize call rehash
 *
 * then calls get index to find what the index of the key would be
 * if there is no collisions is add the key and values into the make
 * if there is a collison
 */
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
		if(map[index]->keyword != v)
			map[index]->addValue(v);

	} else{
		if(c1){

			map[collHash1(index,k, v)] = new hashNode(k,v);
			numKeys++;
			collisionct1++;
		}else {
			map[collHash2(index,k, v)] = new hashNode(k,v);
			numKeys++;
			collisionct1++;
		}
	}

}

/*
 * consumes: a string k they represents the key
 *
 * return the index of the k depending on what hashing function
 * was used
 */
int hashMap::getIndex(string k){
	int index;

	if(h1){
		index = calcHash1(k);

	}else {
		index = calcHash2(k);
	}
	return index;
}

/*
 *consumes: a string k that represents the key
 *
 *return: the new index for that key
 *
 *first hashing function that calulates the hash by adding all the ASCII
 * values of the key
 *
 */
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


/*
 * consumes: a string k that represents the key
 *
 * return: the new index for that key
 *
 * second hashing fucntion that iterates throught the length of the key
 * and calulates the index based on the sequence h = (h*19 + (int)k[i]) % mapSize;
 *
 */
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

/*
 *finds the closest prime to the twice the map Size
 *then sets the closest prime to be the new map Size
 */
void hashMap::getClosestPrime(){
	int doubleArr = mapSize *2;
	int primes[] = {101, 211, 431, 863, 1733, 3467,6997, 13999 ,  28057};
	int i = 0;
	while(doubleArr > primes[i]){
		i++;
	}
	mapSize = primes[i];
}


/*
 * makes a new map that is double the values of the current map, then hashes all the
 * values into the new map and sets the new map to the current map
 */
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


/*
 * consumes: an int i represing the index of the k
 *			 a string k the represnts the k
 * 			 a string v the represent the values associated with the key
 * return: the new index for the key
 *
 * first collison function that handles collions by linear probing
*/
int hashMap::collHash1(int index, string k, string v){
	if(map[index] == NULL){
		return index;
	}else {
		while(map[index] != NULL){
			if(map[index]->keyword == k){
				if(v != "" && map[index]->keyword != v)
					map[index]->addValue(v);
				return index;
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


/*
 * consumes: an int i represing the index of the k
 *			 a string k the represnts the k
 * 			 a string v the represent the values associated with the key
 * return: the new index for the key
 *
 * second collison function that handles collions by quadratic probing
*/
int hashMap::collHash2(int i, string k, string v){
	int factor = 1;


	while(map[i] != NULL ){
		if(map[i]->keyword == k){
			if(v != ""){
				if(map[i]->keyword != v){
					map[i]->addValue(v);
				}
			}
				break;
		}
		factor++;
		i += factor;
		collisionct2++;

		if(i > mapSize){
			i = i % mapSize;
		}


	}

	if(i < 0)
		i *= -1;

	return i;
}


/*
 * consume: a string k that reprents the key
 *
 * find where the key is stroed in the hashMap
 */
int hashMap::findKey(string k){
	int index = getIndex(k);

	if(map[index] == NULL){
		return -1;
	}

	if(map[index]->keyword == k){
		return index;
	}

	if(c1){

		return collHash1(index, k, "");
	}else{
		return collHash2(index, k, "");
	}


	return 0;
}

/*
 * prints out the entire hashMap and all the values
 */
void hashMap::printMap(){
	for(int i = 0 ; i < mapSize; i++){
		if(map[i] != NULL){
			cout << "(key: " << map[i]->keyword << ") ";

			for(int j = 0; j < map[i]->valuesSize; j++){
				cout << map[i]->values[j] << ", ";
			}
		cout << endl;
		}
	}
}

//prints out the number of coll from hashing or handling
void hashMap::printColl(){
	cout << "Coll from hashing " << collisionct1 << endl;
	cout << "Coll from handling " << collisionct2 << endl;

}












