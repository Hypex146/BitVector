#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(GETBIT_, INT8) {
	EXPECT_EQ(getBit<int8_t>(-13, 0), 1);
	EXPECT_EQ(getBit<int8_t>(-13, 1), 1);
	EXPECT_EQ(getBit<int8_t>(-13, 2), 0);
	EXPECT_EQ(getBit<int8_t>(-13, 3), 0);
	EXPECT_EQ(getBit<int8_t>(-13, sizeof(int8_t) * BITS_IN_BYTE - 2), 1);
	EXPECT_EQ(getBit<int8_t>(-13, sizeof(int8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<int8_t>(-13, sizeof(int8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<int8_t>(-13, sizeof(int8_t) * BITS_IN_BYTE * 2), std::out_of_range);
}


TEST(GETBIT_, UINT8) {
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, 0), 1);
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, 1), 1);
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, 2), 0);
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, 3), 0);
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, sizeof(uint8_t) * BITS_IN_BYTE - 2), 1);
	EXPECT_EQ(getBit<uint8_t>((uint8_t) -13, sizeof(uint8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<uint8_t>(-13, sizeof(uint8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<uint8_t>(-13, sizeof(uint8_t) * BITS_IN_BYTE * 2), std::out_of_range);
}


TEST(GETBIT_, INT64) {
	EXPECT_EQ(getBit<int64_t>(-13, 0), 1);
	EXPECT_EQ(getBit<int64_t>(-13, 1), 1);
	EXPECT_EQ(getBit<int64_t>(-13, 2), 0);
	EXPECT_EQ(getBit<int64_t>(-13, 3), 0);
	EXPECT_EQ(getBit<int64_t>(-13, sizeof(int64_t) * BITS_IN_BYTE - 2), 1);
	EXPECT_EQ(getBit<int64_t>(-13, sizeof(int64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<int64_t>(-13, sizeof(int64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<int64_t>(-13, sizeof(int64_t) * BITS_IN_BYTE * 2), std::out_of_range);
}


TEST(GETBIT_, UINT64) {
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, 0), 1);
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, 1), 1);
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, 2), 0);
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, 3), 0);
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, sizeof(uint64_t) * BITS_IN_BYTE - 2), 1);
	EXPECT_EQ(getBit<uint64_t>((uint64_t) -13, sizeof(uint64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<uint64_t>(-13, sizeof(uint64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<uint64_t>(-13, sizeof(uint64_t) * BITS_IN_BYTE * 2), std::out_of_range);
}


TEST(SETBIT_, INT8) {
	EXPECT_EQ(setBit<int8_t>(5, 0, 0), 4);
	EXPECT_EQ(setBit<int8_t>(5, 1, 1), 7);
	EXPECT_EQ(setBit<int8_t>(5, 2, 0), 1);
	EXPECT_EQ(setBit<int8_t>(5, 3, 1), 13);
	EXPECT_EQ(setBit<int8_t>(5, (sizeof(int8_t) * BITS_IN_BYTE - 2), 1), (int8_t) (powl(2, sizeof(int8_t) * BITS_IN_BYTE - 2) + 5));
	EXPECT_EQ(setBit<int8_t>(0, (sizeof(int8_t) * BITS_IN_BYTE - 1), 1), (int8_t) (uint8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(setBit<int8_t>(5, sizeof(int8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<int8_t>(5, sizeof(int8_t) * BITS_IN_BYTE * 2, 1), std::out_of_range);
}


TEST(SETBIT_, UINT8) {
	EXPECT_EQ(setBit<uint8_t>(5, 0, 0), 4);
	EXPECT_EQ(setBit<uint8_t>(5, 1, 1), 7);
	EXPECT_EQ(setBit<uint8_t>(5, 2, 0), 1);
	EXPECT_EQ(setBit<uint8_t>(5, 3, 1), 13);
	EXPECT_EQ(setBit<uint8_t>(5, (sizeof(uint8_t) * BITS_IN_BYTE - 2), 1), (uint8_t) (powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 2) + 5));
	EXPECT_EQ(setBit<uint8_t>(0, (sizeof(uint8_t) * BITS_IN_BYTE - 1), 1), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(setBit<uint8_t>(5, sizeof(uint8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<uint8_t>(5, sizeof(uint8_t) * BITS_IN_BYTE * 2, 1), std::out_of_range);
}


TEST(SETBIT_, INT64) {
	EXPECT_EQ(setBit<int64_t>(5, 0, 0), 4);
	EXPECT_EQ(setBit<int64_t>(5, 1, 1), 7);
	EXPECT_EQ(setBit<int64_t>(5, 2, 0), 1);
	EXPECT_EQ(setBit<int64_t>(5, 3, 1), 13);
	EXPECT_EQ(setBit<int64_t>(5, (sizeof(int64_t) * BITS_IN_BYTE - 2), 1), (int64_t) (powl(2, sizeof(int64_t) * BITS_IN_BYTE - 2) + 5));
	EXPECT_EQ(setBit<int64_t>(0, (sizeof(int64_t) * BITS_IN_BYTE - 1), 1), (int64_t) (uint64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(setBit<int64_t>(5, sizeof(int64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<int64_t>(5, sizeof(int64_t) * BITS_IN_BYTE * 2, 1), std::out_of_range);
}


TEST(SETBIT_, UINT64) {
	EXPECT_EQ(setBit<uint64_t>(5, 0, 0), 4);
	EXPECT_EQ(setBit<uint64_t>(5, 1, 1), 7);
	EXPECT_EQ(setBit<uint64_t>(5, 2, 0), 1);
	EXPECT_EQ(setBit<uint64_t>(5, 3, 1), 13);
	EXPECT_EQ(setBit<uint64_t>(5, (sizeof(uint64_t) * BITS_IN_BYTE - 2), 1), (uint64_t) (powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 2) + 5));
	EXPECT_EQ(setBit<uint64_t>(0, (sizeof(uint64_t) * BITS_IN_BYTE - 1), 1), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(setBit<uint64_t>(5, sizeof(uint64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<uint64_t>(5, sizeof(uint64_t) * BITS_IN_BYTE * 2, 1), std::out_of_range);
}
