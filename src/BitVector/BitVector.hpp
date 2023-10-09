#pragma once


#include <iostream>


namespace bv {

	const uint8_t BITS_IN_BYTE = 8;


	template <std::integral IntType>
	std::string toHex(IntType bits);

	template <std::integral IntType>
	IntType logLeftShift(IntType bits, uint8_t count);

	template <std::integral IntType>
	IntType logRightShift(IntType bits, uint8_t count);
	
	template <std::integral IntType>
	bool getBit(IntType bits, uint8_t offset);
	
	template <std::integral IntType>
	IntType setBit(IntType bits, uint8_t offset, bool bit);
	
	template <std::integral IntType>
	IntType getMask(uint8_t size, uint8_t offset);


	template <std::integral IntType>
	class BitVector {

	private:
		IntType *bits_;
		size_t size_;  // Размер вектора в битах
		uint64_t chunk_count_;  // Количество переменных типа IntType в массиве bits_
		uint8_t chunk_size_;  // Размер типа IntType в битах

	public:
		BitVector();
		
		BitVector(size_t size);
		
		BitVector(size_t size, const IntType *bits);
		
		BitVector(size_t size, const IntType *bits, size_t tmplt_size);
		
		~BitVector();
		
		size_t getSize() const;
		
		void setBits(size_t field_size, const IntType *bits, uint64_t offset);
		
		void setBits(const BitVector<IntType> &bit_vector, uint64_t offset);
		
		IntType *getBits(size_t field_size, uint64_t offset) const;
		
		IntType getFewBits(size_t field_size, uint64_t offset) const;
		
		std::string toString() const;
		
		void print() const;
		
	};

}


#include "BitVector.tpp"
