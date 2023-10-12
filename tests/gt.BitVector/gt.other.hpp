#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(GETMASK_, INT8) {
	EXPECT_EQ(getMask<int8_t>(0, 0), 0);
	EXPECT_EQ(getMask<int8_t>(0, 1), 0);
	EXPECT_EQ(getMask<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(getMask<int8_t>(1, 0), 1);
	EXPECT_EQ(getMask<int8_t>(2, 0), 3);
	EXPECT_EQ(getMask<int8_t>(3, 2), 28);
	EXPECT_EQ(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 0), -1);
	EXPECT_EQ(getMask<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE - 1), (int8_t) -powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(getMask<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE * 2), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE + 1, 0), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 1), std::out_of_range);
}


TEST(GETMASK_, UINT8) {
	EXPECT_EQ(getMask<uint8_t>(0, 0), 0);
	EXPECT_EQ(getMask<uint8_t>(0, 1), 0);
	EXPECT_EQ(getMask<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(getMask<uint8_t>(1, 0), 1);
	EXPECT_EQ(getMask<uint8_t>(2, 0), 3);
	EXPECT_EQ(getMask<uint8_t>(3, 2), 28);
	EXPECT_EQ(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, 0), (uint8_t) -1);
	EXPECT_EQ(getMask<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE - 1), (uint8_t) (int8_t) -powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(getMask<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE * 2), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE + 1, 0), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, 1), std::out_of_range);
}


TEST(GETMASK_, INT64) {
	EXPECT_EQ(getMask<int64_t>(0, 0), 0);
	EXPECT_EQ(getMask<int64_t>(0, 1), 0);
	EXPECT_EQ(getMask<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(getMask<int64_t>(1, 0), 1);
	EXPECT_EQ(getMask<int64_t>(2, 0), 3);
	EXPECT_EQ(getMask<int64_t>(3, 2), 28);
	EXPECT_EQ(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 0), -1);
	EXPECT_EQ(getMask<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE - 1), (int64_t) -powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(getMask<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE * 2), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE + 1, 0), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 1), std::out_of_range);
}


TEST(GETMASK_, UINT64) {
	EXPECT_EQ(getMask<uint64_t>(0, 0), 0);
	EXPECT_EQ(getMask<uint64_t>(0, 1), 0);
	EXPECT_EQ(getMask<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(getMask<uint64_t>(1, 0), 1);
	EXPECT_EQ(getMask<uint64_t>(2, 0), 3);
	EXPECT_EQ(getMask<uint64_t>(3, 2), 28);
	EXPECT_EQ(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, 0), (uint64_t) -1);
	EXPECT_EQ(getMask<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE - 1), (uint64_t) (int64_t) -powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1));
	EXPECT_THROW(getMask<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE * 2), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE + 1, 0), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, 1), std::out_of_range);
}


TEST(TOHEX_, INT8) {
	EXPECT_STREQ(toHex<int8_t>(0).c_str(), "00");
	EXPECT_STREQ(toHex<int8_t>(5).c_str(), "05");
	EXPECT_STREQ(toHex<int8_t>(-1).c_str(), "ff");
}


TEST(TOHEX_, UINT8) {
	EXPECT_STREQ(toHex<uint8_t>(0).c_str(), "00");
	EXPECT_STREQ(toHex<uint8_t>(5).c_str(), "05");
	EXPECT_STREQ(toHex<uint8_t>((uint8_t) -1).c_str(), "ff");
}


TEST(TOHEX_, INT64) {
	EXPECT_STREQ(toHex<int64_t>(0).c_str(), "0000000000000000");
	EXPECT_STREQ(toHex<int64_t>(5).c_str(), "0000000000000005");
	EXPECT_STREQ(toHex<int64_t>(-1).c_str(), "ffffffffffffffff");
}


TEST(TOHEX_, UINT64) {
	EXPECT_STREQ(toHex<uint64_t>(0).c_str(), "0000000000000000");
	EXPECT_STREQ(toHex<uint64_t>(5).c_str(), "0000000000000005");
	EXPECT_STREQ(toHex<uint64_t>((uint64_t) -1).c_str(), "ffffffffffffffff");
}
