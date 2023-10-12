#pragma once


#include <iostream>


namespace bv {

	const uint8_t BITS_IN_BYTE = 8;


	template <std::integral IntType>
	IntType logLeftShift(IntType bits, uint8_t offset);  // HCT

	template <std::integral IntType>
	IntType logRightShift(IntType bits, uint8_t offset);  // HCT
	
	template <std::integral IntType>
	bool getBit(IntType bits, uint8_t position);  // HCT
	
	template <std::integral IntType>
	IntType setBit(IntType bits, uint8_t position, bool bit);  // HCT
	
	template <std::integral IntType>
	IntType getMask(uint8_t size, uint8_t offset);  // HCT
	
	template <std::integral IntType>
	std::string toHex(IntType bits);  // HCT


	template <std::integral IntType>
	class BitVector {

	private:
		IntType *bits_;
		size_t size_;  // Размер вектора в битах
		uint64_t chunk_count_;  // Количество переменных типа IntType в массиве bits_
		uint8_t chunk_size_;  // Размер типа IntType в битах

	public:
		BitVector();  // HCT
		
		BitVector(size_t size);  // HCT
		
		BitVector(size_t size, const IntType *tmplt_bits);  // HCT
		
		BitVector(const BitVector<IntType> &bit_vector);  // HCT
		
		BitVector(BitVector<IntType> &&bit_vector);  // HCT
		
		BitVector<IntType> &operator=(const BitVector<IntType> &bit_vector);  // HCT
		
		BitVector<IntType> &operator=(BitVector<IntType> &&bit_vector);  // HCT
		
		~BitVector();  // HCT
		
		size_t getSize() const;  // HC
		
		void setBit(uint64_t position, bool bit);  // HCT
		
		bool getBit(uint64_t position) const;  // HCT
		
		void setBits(size_t field_size, const IntType *bits, uint64_t offset);  // HCT
		
		void setBits(const BitVector<IntType> &bit_vector, uint64_t offset);  // HCT
		
		BitVector<IntType> getBits(size_t field_size, uint64_t offset) const;  // HCT
		
		template<std::integral RetIntType>
		RetIntType getFewBits(uint8_t field_size, uint64_t offset) const;  // HCT
		
		std::string toString() const;  // HCT
		
	};

}


#include "BitVector.tpp"
