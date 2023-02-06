#include <iostream>
#include "bitVector.h"

int main()
{
	bitVector bVec;
	//bVec.bitSet(12);
	bVec.bitSet(13);
	std::cout << "Result = " << bVec << std::endl;
	bVec.bitReset(12);
	std::cout << "Result = " << bVec << std::endl;
}
