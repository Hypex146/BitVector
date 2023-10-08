#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>


template <std::integral IntType>
IntType bv::logLeftShift(IntType bits, uint8_t count) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (count >= type_size) {
		return 0;
	}
	return bits << count;
}


template <std::integral IntType>
IntType bv::logRightShift(IntType bits, uint8_t count) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (count >= type_size) {
		return 0;
	}
	if  (count == 0) {
		return bits;
	}
	IntType new_bits = setBit(bits >> 1, type_size - 1, 0);
	return new_bits >> (count - 1);
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
bool bv::getBit(IntType bits, uint8_t offset) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (offset >= type_size) {
		throw std::out_of_range("The bit being set is outside of the allowed bits");
	}
	bool bit = logRightShift<IntType>(bits, offset) & 1;
	return bit;
}


template <std::integral IntType>
IntType bv::setBit(IntType bits, uint8_t offset, bool bit) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if (offset >= type_size) {
		throw std::out_of_range("The bit being set is outside of the allowed bits");
	}
	IntType new_bits = bits;
	if (bit) {
		new_bits |= logLeftShift<IntType>(1, offset);
	} else {
		new_bits &= ~logLeftShift<IntType>(1, offset);
	}
	return new_bits;
}


template <std::integral IntType>
IntType bv::getMask(uint8_t size, uint8_t offset) {
	uint8_t type_size = sizeof(IntType) * BITS_IN_BYTE;
	if ((size + offset) > type_size) {
		throw std::out_of_range("Going beyond the border of mask");
	}
	IntType mask = ~logLeftShift<IntType>(-1, size);
	mask = logLeftShift<IntType>(mask, offset);
	return mask;
}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector() : BitVector(sizeof(IntType) * bv::BITS_IN_BYTE, nullptr) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size) : BitVector(size, nullptr) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size, const IntType *bits) : BitVector(size, bits, size) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size, const IntType *bits, size_t tmplt_size) {
	if (size == 0) {
		throw std::invalid_argument("Invalid vector size value");
	}
	if (tmplt_size == 0) {
		throw std::invalid_argument("Invalid template vector size value");
	}
	if (size < tmplt_size) {
		throw std::invalid_argument("Value \"tmplt_size\" should not be more than value \"size\"");
	}
	chunk_size_ = sizeof(IntType) * BITS_IN_BYTE;
	size_ = size;
	chunk_count_ = ceil((double) size_ / (double) (chunk_size_));
	bits_ = new IntType[chunk_count_]{};
	if (bits == nullptr) {
		return;
	}
	if (size_ <= tmplt_size) {
		uint8_t remain_bits = size_ % (chunk_size_);
		std::copy_n(bits, chunk_count_, bits_);
		if (remain_bits > 0) {
			bits_[chunk_count_ - 1] &= getMask<IntType>(remain_bits, 0);
		}
	} else {
		uint64_t tmplt_chunk_count = ceil((double) tmplt_size / (double) (chunk_size_));
		uint8_t tmplt_remain_bits = tmplt_size % (chunk_size_);
		std::copy_n(bits, tmplt_chunk_count, bits_);
		if (tmplt_remain_bits > 0) {
			bits_[tmplt_chunk_count - 1] &= getMask<IntType>(tmplt_remain_bits, 0);
		}
	}
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
void bv::BitVector<IntType>::setBits(size_t field_size, const IntType *bits, uint64_t offset) {
	if (field_size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	uint64_t base_bit_index = offset;
	uint64_t tmplt_bit_index = 0;
	for (int i = 0; i < field_size; i++) {
		uint64_t base_chunk_index = base_bit_index / (chunk_size_);
		uint8_t base_chunk_bit_index = base_bit_index % (chunk_size_);
		uint64_t tmplt_chunk_index = tmplt_bit_index / (chunk_size_);
		uint8_t tmplt_chunk_bit_index = tmplt_bit_index % (chunk_size_);
		bits_[base_chunk_index] = setBit<IntType>(bits_[base_chunk_index], base_chunk_bit_index, getBit<IntType>(bits[tmplt_chunk_index], tmplt_chunk_bit_index));
		base_bit_index++;
		tmplt_bit_index++;
	}
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBits(const BitVector<IntType> &bit_vector, uint64_t offset) {
	setBits(bit_vector.size_, bit_vector.bits_, offset);
}


template <std::integral IntType>
IntType *bv::BitVector<IntType>::getBits(size_t field_size, uint64_t offset) const {
	if (field_size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	IntType *ret_bits = new IntType[(uint64_t) ceil((double) field_size / (double) (chunk_size_))]{};
	uint64_t base_bit_index = offset;
	uint64_t ret_bit_index = 0;
	for (int i = 0; i < field_size; i++) {
		uint64_t base_chunk_index = base_bit_index / (chunk_size_);
		uint8_t base_chunk_bit_index = base_bit_index % (chunk_size_);
		uint64_t ret_chunk_index = ret_bit_index / (chunk_size_);
		uint8_t ret_chunk_bit_index = ret_bit_index % (chunk_size_);
		ret_bits[ret_chunk_index] = setBit<IntType>(ret_bits[ret_chunk_index], ret_chunk_bit_index, getBit<IntType>(bits_[base_chunk_index], base_chunk_bit_index));
		base_bit_index++;
		ret_bit_index++;
	}
	return ret_bits;
}


template<std::integral IntType>
IntType bv::BitVector<IntType>::getFewBits(size_t field_size, uint64_t offset) const {
	if ((field_size + offset > size_) || (field_size > chunk_size_)) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	IntType res;
	uint64_t base_bit_index = offset;
	uint8_t ret_bit_index = 0;
	for (int i = 0; i < field_size; i++) {
		uint64_t base_chunk_index = base_bit_index / (chunk_size_);
		uint8_t base_chunk_bit_index = base_bit_index % (chunk_size_);
		res = setBit<IntType>(res, ret_bit_index, getBit<IntType>(bits_[base_chunk_index], base_chunk_bit_index));
		base_bit_index++;
		ret_bit_index++;
	}
	return res;
}


template <std::integral IntType>
std::string bv::BitVector<IntType>::toString() const {
	std::stringstream str_stream;
	uint8_t remain_bits = size_ % (chunk_size_);
	uint8_t remain_dig = ceil((double) remain_bits / 4.0);
	for (uint64_t i = 0; i < chunk_count_ - 1; i++) {
		str_stream << toHex<IntType>(bits_[i]) << " ";
	}
	std::string hex_str = toHex<IntType>(bits_[chunk_count_ - 1]);
	if (remain_dig > 0) {
		str_stream << hex_str.substr(hex_str.size() - remain_dig);
	} else {
		str_stream << hex_str;
	}
	return str_stream.str();
}


template <std::integral IntType> 
void bv::BitVector<IntType>::print() const {
	std::cout << "Vector size: " << size_ << " Chuck size: " << chunk_size_ 
		<< " Chunk count: " << chunk_count_ << std::endl;
	std::cout << toString() << std::endl;
}
