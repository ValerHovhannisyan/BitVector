#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H
#include <iostream>

class bitVector
{
public:
	bitVector();
	bitVector(std::size_t);
	~bitVector();
public:	
	friend std::ostream& operator<<(std::ostream&, const bitVector&);	
	// std::string m_to_binary(int, std::size_t) const;
	bool operator[](std::size_t);
	void bitSet(std::size_t);
	void bitReset(std::size_t);
	bool bitGet(std::size_t) const;
	void bitResize(std::size_t);
private:
	std::size_t bitSize;
	std::size_t* bitArr;   
};




#endif      //BIT_VECTOR_H
