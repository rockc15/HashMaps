/*
 * main.cpp
 *
 *  Created on: Nov 19, 2019
 *      Author: casey
 */

#include "hashMap.hpp"
#include "makeSeuss.hpp"


int main(){
	srand(time(NULL));
	/*
	 * TEST 1:
	 * 		hashing: adding ASCII values for the
	 * 		collisons: linear probling
	 */
	makeSeuss trial = makeSeuss("DrSeuss.txt", "output_firstHash_firstColl.txt", true, true);

	/*
	 * TEST 2:
	 * 		hashing: Use all N characters of string as an N-digit base-19 number
	 * 		collisons: linear probling
	 */
    makeSeuss trial2 = makeSeuss("DrSeuss.txt", "output_secondHash_firstColl.txt", false, true);

    /*
	 * TEST 3:
	 * 		hashing: adding ASCII values for the
	 * 		collisons: quadratic probling
	 */
	makeSeuss trial3 = makeSeuss("DrSeuss.txt", "output_secondHash_firstColl.txt", true, false);

	/*
	 * TEST 4:
	 * 		hashing: Use all N characters of string as an N-digit base-19 number
	 * 		collisons: quadratic  probling
	 */
	makeSeuss trial4 = makeSeuss("DrSeuss.txt", "output_secondHash_secondColl.txt", false, false);
return 0;
}
