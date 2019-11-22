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
	makeSeuss trial = makeSeuss("DrSeuss.txt", "output0.txt", true, true);

   makeSeuss trial2 = makeSeuss("DrSeuss.txt", "output1.txt", false, true);

//	makeSeuss trial3 = makeSeuss("DrSeuss.txt", "output0.txt", true, false);
//
//	makeSeuss trial4 = makeSeuss("DrSeuss.txt", "output1.txt", false, false);
return 0;
}
