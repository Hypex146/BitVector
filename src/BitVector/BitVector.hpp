#pragma once


#include <iostream>


namespace bv {

	const uint8_t BITS_IN_BYTE = 8;


	template <std::integral IntType>
	std::string toHex(IntType chunk);

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
		IntType *chunks_;
		size_t size_;  // bit
		uint64_t chunk_count_;
		uint8_t chunk_size_;  // byte

	public:
		BitVector();
		
		BitVector(size_t size);
		
		BitVector(size_t size, IntType *bits);
		
		BitVector(size_t size, IntType *bits, size_t tmplt_size);
		
		~BitVector();
		
		size_t getSize() const;
		
		void setBits(size_t size, IntType *bits, size_t offset);
		
		void setBits(BitVector<IntType> &bitVector, size_t offset);
		
		IntType *getBits(size_t size, size_t offset);
		
		IntType getFewBits(size_t size, size_t offset);
		
		std::string toString() const;
		
		void print() const;
		
	};

}


#include "Bitvector.tpp"
