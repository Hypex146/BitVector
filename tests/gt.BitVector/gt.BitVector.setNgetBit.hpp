#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(SETBIT, INT8) {
	int8_t bits[] = {-1, 0};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	bv1.setBit(0, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "ff01");
	bv1.setBit(2, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "ff05");
	bv1.setBit(sizeof(int8_t) * BITS_IN_BYTE * 2 - 1, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "7f05");
}


TEST(SETBIT, INT64) {
	int64_t bits[] = {-1, 0};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	bv1.setBit(0, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "ffffffffffffffff0000000000000001");
	bv1.setBit(2, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "ffffffffffffffff0000000000000005");
	bv1.setBit(sizeof(int64_t) * BITS_IN_BYTE * 2 - 1, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "7fffffffffffffff0000000000000005");
}


TEST(GETBIT, INT8) {
	int8_t bits[] = {-1, 5};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_EQ(bv1.getBit(0), 1);
	EXPECT_EQ(bv1.getBit(1), 0);
	EXPECT_EQ(bv1.getBit(2), 1);
	EXPECT_EQ(bv1.getBit(sizeof(int8_t) * BITS_IN_BYTE * 2 - 1), 1);
}


TEST(GETBIT, INT64) {
	int64_t bits[] = {-1, 5};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_EQ(bv1.getBit(0), 1);
	EXPECT_EQ(bv1.getBit(1), 0);
	EXPECT_EQ(bv1.getBit(2), 1);
	EXPECT_EQ(bv1.getBit(sizeof(int64_t) * BITS_IN_BYTE * 2 - 1), 1);
}
