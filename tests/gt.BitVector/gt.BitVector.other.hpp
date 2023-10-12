#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(GETSIZE, INT8) {
	BitVector<int8_t> bv1 = BitVector<int8_t>(1);
	EXPECT_EQ(bv1.getSize(), 1);
	BitVector<int8_t> bv2 = BitVector<int8_t>(3);
	EXPECT_EQ(bv2.getSize(), 3);
	BitVector<int8_t> bv3 = BitVector<int8_t>(sizeof(int8_t) * 5 + 5);
	EXPECT_EQ(bv3.getSize(), sizeof(int8_t) * 5 + 5);
	BitVector<int8_t> bv4 = BitVector<int8_t>(sizeof(int8_t) * 5);
	EXPECT_EQ(bv4.getSize(), sizeof(int8_t) * 5);
}


TEST(GETSIZE, INT64) {
	BitVector<int64_t> bv1 = BitVector<int64_t>(1);
	EXPECT_EQ(bv1.getSize(), 1);
	BitVector<int64_t> bv2 = BitVector<int64_t>(3);
	EXPECT_EQ(bv2.getSize(), 3);
	BitVector<int64_t> bv3 = BitVector<int64_t>(sizeof(int64_t) * 5 + 5);
	EXPECT_EQ(bv3.getSize(), sizeof(int64_t) * 5 + 5);
	BitVector<int64_t> bv4 = BitVector<int64_t>(sizeof(int64_t) * 5);
	EXPECT_EQ(bv4.getSize(), sizeof(int64_t) * 5);
}
	
	