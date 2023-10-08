#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(LOGLEFTSHIFT, INT8_T) {
	EXPECT_EQ(logLeftShift<int8_t>(0, 0), 0);
	EXPECT_EQ(logLeftShift<int8_t>(0, 1), 0);
	EXPECT_EQ(logLeftShift<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logLeftShift<int8_t>(-1, 0), -1);
	EXPECT_EQ(logLeftShift<int8_t>(-1, 1), -2);
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGLEFTSHIFT, UINT8_T) {
	EXPECT_EQ(logLeftShift<uint8_t>(0, 0), 0);
	EXPECT_EQ(logLeftShift<uint8_t>(0, 1), 0);
	EXPECT_EQ(logLeftShift<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, 0), (uint8_t) -1);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, 1), (uint8_t) -2);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGLEFTSHIFT, INT64_T) {
	EXPECT_EQ(logLeftShift<int64_t>(0, 0), 0);
	EXPECT_EQ(logLeftShift<int64_t>(0, 1), 0);
	EXPECT_EQ(logLeftShift<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logLeftShift<int64_t>(-1, 0), -1);
	EXPECT_EQ(logLeftShift<int64_t>(-1, 1), -2);
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGLEFTSHIFT, UINT64_T) {
	EXPECT_EQ(logLeftShift<uint64_t>(0, 0), 0);
	EXPECT_EQ(logLeftShift<uint64_t>(0, 1), 0);
	EXPECT_EQ(logLeftShift<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, 0), (uint64_t) -1);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, 1), (uint64_t) -2);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGRIGHTSHIFT, INT8_T) {
	EXPECT_EQ(logRightShift<int8_t>(0, 0), 0);
	EXPECT_EQ(logRightShift<int8_t>(0, 1), 0);
	EXPECT_EQ(logRightShift<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logRightShift<int8_t>(-1, 0), -1);
	EXPECT_EQ(logRightShift<int8_t>(-1, 1), 127);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGRIGHTSHIFT, UINT8_T) {
	EXPECT_EQ(logRightShift<uint8_t>(0, 0), 0);
	EXPECT_EQ(logRightShift<uint8_t>(0, 1), 0);
	EXPECT_EQ(logRightShift<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) -1, 0), (uint8_t)  -1);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) -1, 1), 127);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGRIGHTSHIFT, INT64_T) {
	EXPECT_EQ(logRightShift<int64_t>(0, 0), 0);
	EXPECT_EQ(logRightShift<int64_t>(0, 1), 0);
	EXPECT_EQ(logRightShift<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logRightShift<int64_t>(-1, 0), -1);
	EXPECT_EQ(logRightShift<int64_t>(-1, 1), 9223372036854775807);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE * 2 - 1), 0);
}


TEST(LOGRIGHTSHIFT, UINT64_T) {
	EXPECT_EQ(logRightShift<uint64_t>(0, 0), 0);
	EXPECT_EQ(logRightShift<uint64_t>(0, 1), 0);
	EXPECT_EQ(logRightShift<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE * 2 - 1), 0);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) -1, 0), (uint64_t)  -1);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) -1, 1), 9223372036854775807);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE * 2 - 1), 0);
}
