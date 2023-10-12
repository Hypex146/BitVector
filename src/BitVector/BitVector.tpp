#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>


template <std::integral IntType>
IntType bv::logLeftShift(IntType bits, uint8_t offset) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (offset >= type_size) {
		return 0;
	}
	return bits << offset;
}


template <std::integral IntType>
IntType bv::logRightShift(IntType bits, uint8_t offset) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (offset >= type_size) {
		return 0;
	}
	if  (offset == 0) {
		return bits;
	}
	bits = setBit<IntType>(bits >> 1, type_size - 1, 0);
	return bits >> (offset - 1);
}


template <std::integral IntType>
bool bv::getBit(IntType bits, uint8_t position) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (position >= type_size) {
		throw std::out_of_range("The bit being get is outside of the allowed bits");
	}
	return logRightShift<IntType>(bits, position) & 1;
}


template <std::integral IntType>
IntType bv::setBit(IntType bits, uint8_t position, bool bit) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (position >= type_size) {
		throw std::out_of_range("The bit being set is outside of the allowed bits");
	}
	if (bit) {
		bits |= logLeftShift<IntType>(1, position);
	} else {
		bits &= ~logLeftShift<IntType>(1, position);
	}
	return bits;
}


template <std::integral IntType>
IntType bv::getMask(uint8_t size, uint8_t offset) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if ((size + offset) > type_size) {
		throw std::out_of_range("Going beyond the border of mask");
	}
	IntType mask = ~logLeftShift<IntType>(-1, size);
	return logLeftShift<IntType>(mask, offset);
}


template <std::integral IntType>
std::string bv::toHex(IntType bits) {
	std::stringstream str_stream;
	uint8_t hex_str_size = sizeof(IntType) * 2;
	str_stream 
		<< std::setfill('0') << std::setw(hex_str_size) 
		<< std::hex << (int64_t) bits;
	std::string hex_str = str_stream.str();
	return hex_str.substr(hex_str.size() - hex_str_size);
}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector() : BitVector(sizeof(IntType) * BITS_IN_BYTE, nullptr) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size) : BitVector(size, nullptr) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size, const IntType *tmplt_bits) {
	if (size == 0) {
		throw std::invalid_argument("Invalid vector size value");
	}
	chunk_size_ = sizeof(IntType) * BITS_IN_BYTE;
	size_ = size;
	chunk_count_ = ceil((double) size_ / (double) (chunk_size_));
	bits_ = new IntType[chunk_count_]{};
	if (tmplt_bits == nullptr) {
		return;
	}
	uint8_t remain_bits = size_ % (chunk_size_);
	std::copy_n(tmplt_bits, chunk_count_, bits_);
	if (remain_bits > 0) {
		bits_[0] &= getMask<IntType>(remain_bits, 0);
	}
}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(const BitVector<IntType> &bit_vector) {
	size_ = bit_vector.size_;
	chunk_count_ = bit_vector.chunk_count_;
	chunk_size_ = bit_vector.chunk_size_;
	bits_ = new IntType[chunk_count_];
	std::copy_n(bit_vector.bits_, chunk_count_, bits_);
	//std::cout << "Copy constr" << std::endl;
}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(BitVector<IntType> &&bit_vector) {
	size_ = bit_vector.size_;
	chunk_count_ = bit_vector.chunk_count_;
	chunk_size_ = bit_vector.chunk_size_;
	bits_ = bit_vector.bits_;
	bit_vector.bits_ = nullptr;
	//std::cout << "Move constr" << std::endl;
}


template <std::integral IntType>
bv::BitVector<IntType> &bv::BitVector<IntType>::operator=(const BitVector<IntType> &bit_vector) {
	//std::cout << "Copy op" << std::endl;
	if (this == &bit_vector) {
		return *this;
	}
	delete[] bits_;
	size_ = bit_vector.size_;
	chunk_count_ = bit_vector.chunk_count_;
	chunk_size_ = bit_vector.chunk_size_;
	bits_ = new IntType[chunk_count_];
	std::copy_n(bit_vector.bits_, chunk_count_, bits_);
	return *this;
}


template <std::integral IntType>
bv::BitVector<IntType> &bv::BitVector<IntType>::operator=(BitVector<IntType> &&bit_vector) {
	//std::cout << "Move op" << std::endl;
	if (this == &bit_vector) {
		return *this;
	}
	delete[] bits_;
	size_ = bit_vector.size_;
	chunk_count_ = bit_vector.chunk_count_;
	chunk_size_ = bit_vector.chunk_size_;
	bits_ = bit_vector.bits_;
	bit_vector.bits_ = nullptr;
	return *this;
}


template <std::integral IntType>
bv::BitVector<IntType>::~BitVector() {
	delete[] bits_;
}


template <std::integral IntType>
size_t bv::BitVector<IntType>::getSize() const {
	return size_;
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBit(uint64_t position, bool bit) {
	if (position >= size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	uint64_t chunk_index = chunk_count_ - (position / chunk_size_) - 1;
	uint8_t bit_index = position % chunk_size_;
	bits_[chunk_index] = bv::setBit<IntType>(bits_[chunk_index], bit_index, bit);
}


template <std::integral IntType>
bool bv::BitVector<IntType>::getBit(uint64_t position) const {
	if (position >= size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	uint64_t chunk_index = chunk_count_ - (position / chunk_size_) - 1;
	uint8_t bit_index = position % chunk_size_;
	return bv::getBit<IntType>(bits_[chunk_index], bit_index);
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBits(size_t field_size, const IntType *bits, uint64_t offset) {
	if (field_size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	if (field_size == 0) {
		throw std::invalid_argument("Invalid field size value");
	}
	uint64_t base_bit_pos = offset;
	uint64_t field_chunk_count = ceil((double) field_size / (double) (chunk_size_));
	for (uint64_t field_bit_pos = 0; field_bit_pos < field_size; field_bit_pos++) {
		uint64_t field_chunk_index = field_chunk_count - (field_bit_pos / chunk_size_) - 1;
		uint8_t field_bit_index = field_bit_pos % chunk_size_;
		setBit(base_bit_pos, bv::getBit<IntType>(bits[field_chunk_index], field_bit_index));
		base_bit_pos++;
	}
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBits(const BitVector<IntType> &bit_vector, uint64_t offset) {
	setBits(bit_vector.size_, bit_vector.bits_, offset);
}


template <std::integral IntType>
bv::BitVector<IntType> bv::BitVector<IntType>::getBits(size_t field_size, uint64_t offset) const {
	if (field_size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	if (field_size == 0) {
		throw std::invalid_argument("Invalid field size value");
	}
	BitVector<IntType> bit_vector = BitVector<IntType>(field_size);
	for (int i = 0; i < field_size; i++) {
		bit_vector.setBit(i, getBit(offset + i));
	}
	return bit_vector;
}


template <std::integral IntType>
template<std::integral RetIntType>
RetIntType bv::BitVector<IntType>::getFewBits(uint8_t field_size, uint64_t offset) const {
	uint8_t type_size = sizeof(RetIntType) * BITS_IN_BYTE;
	if (field_size + offset > size_ || field_size > type_size) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	if (field_size == 0) {
		throw std::invalid_argument("Invalid field size value");
	}
	RetIntType bits = 0;
	uint64_t base_bit_pos = offset;
	for (uint64_t field_bit_pos = 0; field_bit_pos < field_size; field_bit_pos++) {
		bits = bv::setBit<RetIntType>(bits, field_bit_pos, getBit(base_bit_pos));
		base_bit_pos++;
	}
	return bits;
}


template <std::integral IntType>
std::string bv::BitVector<IntType>::toString() const {
	std::stringstream str_stream;
	uint8_t remain_bits = size_ % (chunk_size_);
	uint8_t remain_dig = ceil((double) remain_bits / 4.0);
	std::string hex_str = toHex<IntType>(bits_[0]);
	if (remain_dig > 0) {
		str_stream << hex_str.substr(hex_str.size() - remain_dig);
	} else {
		str_stream << hex_str;
	}
	for (uint64_t i = 1; i < chunk_count_; i++) {
		str_stream << toHex<IntType>(bits_[i]);
	}
	return str_stream.str();
}
