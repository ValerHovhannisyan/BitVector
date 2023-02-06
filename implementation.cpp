#include <iostream>
#include "bitVector.h"

bitVector::bitVector()
{
	bitSize = 1;
	bitArr = new std::size_t[bitSize];
}

bool bitVector::operator[](std::size_t pos)
{
	if (pos >= bitSize * (sizeof(std::size_t) * 8))
	{
		throw std::out_of_range("Invalid index!");
	}
	std::size_t ind = pos / (sizeof(std::size_t) * 8);
	return bitArr[ind] & ((1 << (pos - (sizeof(std::size_t) * 8 * ind))));
}

std::ostream& operator<<(std::ostream& os, const bitVector& obj)
{	
	std::string binary_num = "";
	int num = 0;
	int tmpSize = obj.bitSize / (sizeof(size_t) * 8);
	for (int i = 0; i <= tmpSize; ++i)
	{	
		num = obj.bitArr[i];
		for (int i = 0; i < sizeof(size_t) * 8; ++i)
		{
			binary_num.insert(0,std::to_string(num % 2));
			num /= 2;
		}
		os << binary_num;
	}
	std::cout << std::endl;
	return os;
}

void bitVector::bitResize(std::size_t position)
{
	std::size_t newSize = position / (sizeof(std::size_t) * 8);
	std::size_t* tmp = new std::size_t[++newSize];
	for (int i = 0; i < bitSize; ++i)
	{
		tmp[i] = bitArr[i];
	}
	delete[] bitArr;
	bitArr = tmp;
	tmp = nullptr;
	bitSize = newSize;
}

void bitVector::bitSet(std::size_t pos)
{
	if (pos >= bitSize * (sizeof(std::size_t) * 8))
	{	
		bitResize(pos);
	}
	std::size_t ind = pos / (sizeof(std::size_t) * 8);
	std::cout << "Before the change = " << bitArr[ind] << std::endl;
	bitArr[ind] |= ((1 << (pos - (sizeof(std::size_t) * 8 * ind))));
	std::cout << "After the change = " << bitArr[ind] << std::endl;
}

void bitVector::bitReset(std::size_t pos)
{
	if (pos>= bitSize * (sizeof(std::size_t) * 8))
	{
		bitResize(pos);
	}
	std::size_t ind = pos / (sizeof(std::size_t) * 8);
	std::cout << "Before the change = " << bitArr[ind] << std::endl;
	bitArr[ind] ^= ((1 << (pos - (sizeof(std::size_t) * 8 * ind))));
	std::cout << "After the change = " << bitArr[ind] << std::endl;
}

bool bitVector::bitGet(std::size_t pos) const
{
    if (pos >= bitSize * (sizeof(std::size_t) * 8))
    {
        throw std::out_of_range("Invalid index!");
    }
    std::size_t ind = pos / (sizeof(std::size_t) * 8);
    return bitArr[ind] & ((1 << (pos - (sizeof(std::size_t) * 8 * ind))));
}

bitVector::~bitVector()
{
	delete[] bitArr;
	bitArr = nullptr;
}