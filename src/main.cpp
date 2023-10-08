#include <iostream>
#include <cmath>
#include "BitVector.hpp"


using namespace bv;


int main(int argc, char *argv[]) {
	std::cout << "Hello, World!" << std::endl;
	
	int8_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	size_t max_size = 32;
	size_t size = 15;
	size_t offset = 11;
	BitVector<int8_t> v1 = BitVector<int8_t>(max_size);
	BitVector<int8_t> v2 = BitVector<int8_t>(max_size);
	v1.setBits_(size, bits, offset);
	v2.setBits(size, bits, offset);
	std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
	std::cout << "V1: " << v1.toString() << std::endl;
	std::cout << "V2: " << v2.toString() << std::endl;

	std::cout << "Bye!" << std::endl;
	return 0;
}

// 00000000 00000000 00000000 00000000 (32)
// 11111111 1111111 (15)
// >> 11
// 00000000 00011111 11111111 11000000
