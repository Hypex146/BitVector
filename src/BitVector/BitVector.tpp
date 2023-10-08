#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>


template <std::integral IntType>
IntType bv::logLeftShift(IntType bits, uint8_t count) {
	if (count >= sizeof(IntType) * bv::BITS_IN_BYTE) {
		return 0;
	}
	return bits << count;
}


template <std::integral IntType>
IntType bv::logRightShift(IntType bits, uint8_t count) {
	if (count >= sizeof(IntType) * bv::BITS_IN_BYTE) {
		return 0;
	}
	if  (count == 0) {
		return bits;
	}
	IntType new_bits = setBit(bits >> 1, sizeof(IntType) * bv::BITS_IN_BYTE - 1, 0);
	return new_bits >> (count - 1);
}


template <std::integral IntType>
std::string bv::toHex(IntType chunk) {
	std::stringstream str_stream;
	uint8_t res_str_size = sizeof(IntType) * 2;
	str_stream 
		<< std::setfill('0') << std::setw(res_str_size) 
		<< std::hex << (int64_t) chunk;
	std::string hex_str = str_stream.str();
	return hex_str.substr(hex_str.size() - res_str_size);
}


template <std::integral IntType>
bool bv::getBit(IntType bits, uint8_t offset) {
	uint8_t size = sizeof(IntType);
	if (offset >= size * bv::BITS_IN_BYTE) {
		throw std::out_of_range("The bit being set is outside of the allowed bits");
	}
	bool res = logRightShift<IntType>(bits, offset) & 1;
	return res;
}


template <std::integral IntType>
IntType bv::setBit(IntType bits, uint8_t offset, bool bit) {
	uint8_t size = sizeof(IntType);
	if (offset >= size * bv::BITS_IN_BYTE) {
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
	uint8_t type_size = sizeof(IntType);
	if ((size + offset) > type_size * bv::BITS_IN_BYTE) {
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
bv::BitVector<IntType>::BitVector(size_t size, IntType *bits) : BitVector(size, bits, size) {}


template <std::integral IntType>
bv::BitVector<IntType>::BitVector(size_t size, IntType *bits, size_t tmplt_size) {
	if (size == 0) {
		throw std::invalid_argument("Invalid vector size value");
	}
	if (tmplt_size == 0) {
		throw std::invalid_argument("Invalid template vector size value");
	}
	if (size < tmplt_size) {
		throw std::invalid_argument("Value \"tmplt_size\" should not be more than value \"size\"");
	}
	chunk_size_ = sizeof(IntType);
	size_ = size;
	chunk_count_ = ceil((double) size_ / (double) (bv::BITS_IN_BYTE * chunk_size_));
	chunks_ = new IntType[chunk_count_]{};
	if (bits == nullptr) {
		return;
	}
	if (size_ <= tmplt_size) {
		uint8_t remain_bits = size_ % (chunk_size_ * bv::BITS_IN_BYTE);
		std::copy_n(bits, chunk_count_, chunks_);
		if (remain_bits > 0) {
			chunks_[chunk_count_ - 1] &= ~(logLeftShift<IntType>(-1, remain_bits));
		}
	} else {
		uint64_t tmplt_chunk_count = ceil((double) tmplt_size / (double) (bv::BITS_IN_BYTE * chunk_size_));
		uint8_t tmplt_remain_bits = tmplt_size % (chunk_size_ * bv::BITS_IN_BYTE);  // TODO remain is remain)) %
		std::copy_n(bits, tmplt_chunk_count, chunks_);
		if (tmplt_remain_bits > 0) {
			chunks_[tmplt_chunk_count - 1] &= ~(logLeftShift<IntType>(-1, tmplt_remain_bits));
		}
	}
}


template <std::integral IntType>
bv::BitVector<IntType>::~BitVector() {
	delete[] chunks_;
}


template <std::integral IntType>
size_t bv::BitVector<IntType>::getSize() const {
	return size_;
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBits(size_t size, IntType *bits, size_t offset) {
	if (size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	uint64_t index = offset;
	uint64_t tmplt_index = 0;
	for (int i = 0; i < size; i++) {
		uint64_t chunk_index = index / (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t bit_index = index % (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t tmplt_chunk_index = tmplt_index / (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t tmplt_bit_index = tmplt_index % (bv::BITS_IN_BYTE * chunk_size_);
		chunks_[chunk_index] = setBit<IntType>(chunks_[chunk_index], bit_index, getBit<IntType>(bits[tmplt_chunk_index], tmplt_bit_index));
		index++;
		tmplt_index++;
	}
}


template <std::integral IntType>
void bv::BitVector<IntType>::setBits(BitVector<IntType> &bitVector, size_t offset) {
	setBits(bitVector.size_, bitVector.chunks_, offset);
}


template <std::integral IntType>
IntType *bv::BitVector<IntType>::getBits(size_t size, size_t offset) {
	if (size + offset > size_) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	IntType *bits = new IntType[(size_t) ceil((double) size / (double) (bv::BITS_IN_BYTE * chunk_size_))]{};
	uint64_t index = offset;
	uint64_t tmplt_index = 0;
	for (int i = 0; i < size; i++) {
		uint64_t chunk_index = index / (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t bit_index = index % (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t tmplt_chunk_index = tmplt_index / (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t tmplt_bit_index = tmplt_index % (bv::BITS_IN_BYTE * chunk_size_);
		bits[tmplt_chunk_index] = setBit<IntType>(bits[tmplt_chunk_index], tmplt_bit_index, getBit<IntType>(chunks_[chunk_index], bit_index));
		index++;
		tmplt_index++;
	}
	return bits;
}


template<std::integral IntType>
IntType bv::BitVector<IntType>::getFewBits(size_t size, size_t offset) {
	if ((size + offset > size_) || (size > bv::BITS_IN_BYTE * chunk_size_)) {
		throw std::out_of_range("Going beyond the border of bit vector");
	}
	IntType res;
	uint64_t index = offset;
	uint64_t tmplt_index = 0;
	for (int i = 0; i < size; i++) {
		uint64_t chunk_index = index / (bv::BITS_IN_BYTE * chunk_size_);
		uint64_t bit_index = index % (bv::BITS_IN_BYTE * chunk_size_);
		res = setBit<IntType>(res, tmplt_index, getBit<IntType>(chunks_[chunk_index], bit_index));
		index++;
		tmplt_index++;
	}
	return res;
}


template <std::integral IntType>
std::string bv::BitVector<IntType>::toString() const {
	std::stringstream str_stream;
	uint8_t remain_bits = size_ % (chunk_size_ * bv::BITS_IN_BYTE);
	uint8_t remain_dig = ceil((double) remain_bits / 4.0);
	for (uint64_t i = 0; i < chunk_count_ - 1; i++) {
		str_stream << toHex<IntType>(chunks_[i]) << " ";
	}
	std::string hex_str = toHex<IntType>(chunks_[chunk_count_ - 1]);
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
