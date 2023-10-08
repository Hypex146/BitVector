#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(BITVECTOR_0, INT8_T) {
	BitVector<int8_t> v1 = BitVector<int8_t>();
	EXPECT_STREQ(v1.toString().c_str(), "00");
}


TEST(BITVECTOR_0, UINT8_T) {
	BitVector<uint8_t> v1 = BitVector<uint8_t>();
	EXPECT_STREQ(v1.toString().c_str(), "00");
}


TEST(BITVECTOR_0, INT16_T) {
	BitVector<int16_t> v1 = BitVector<int16_t>();
	EXPECT_STREQ(v1.toString().c_str(), "0000");
}


TEST(BITVECTOR_0, UINT16_T) {
	BitVector<uint16_t> v1 = BitVector<uint16_t>();
	EXPECT_STREQ(v1.toString().c_str(), "0000");
}


TEST(BITVECTOR_0, INT32_T) {
	BitVector<int32_t> v1 = BitVector<int32_t>();
	EXPECT_STREQ(v1.toString().c_str(), "00000000");
}


TEST(BITVECTOR_0, UINT32_T) {
	BitVector<uint32_t> v1 = BitVector<uint32_t>();
	EXPECT_STREQ(v1.toString().c_str(), "00000000");
}


TEST(BITVECTOR_0, INT64_T) {
	BitVector<int64_t> v1 = BitVector<int64_t>();
	EXPECT_STREQ(v1.toString().c_str(), "0000000000000000");
}


TEST(BITVECTOR_0, UINT64_T) {
	BitVector<uint64_t> v1 = BitVector<uint64_t>();
	EXPECT_STREQ(v1.toString().c_str(), "0000000000000000");
}


TEST(BITVECTOR_1, INT8_T) {
	BitVector<int8_t> v1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "00");
	BitVector<int8_t> v2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "00 00");
	BitVector<int8_t> v3 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v3.toString().c_str(), "00 00 00 00");
	BitVector<int8_t> v4 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v4.toString().c_str(), "00 00 0");
	BitVector<int8_t> v5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 - 1);
	EXPECT_STREQ(v5.toString().c_str(), "00 00 00");
	BitVector<int8_t> v6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v6.toString().c_str(), "00 00 0");
	BitVector<int8_t> v7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v7.toString().c_str(), "00 00 00");
	EXPECT_THROW(BitVector<int8_t>(0), std::invalid_argument);
}


TEST(BITVECTOR_1, UINT8_T) {
	BitVector<uint8_t> v1 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "00");
	BitVector<uint8_t> v2 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "00 00");
	BitVector<uint8_t> v3 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v3.toString().c_str(), "00 00 00 00");
	BitVector<uint8_t> v4 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v4.toString().c_str(), "00 00 0");
	BitVector<uint8_t> v5 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 3 - 1);
	EXPECT_STREQ(v5.toString().c_str(), "00 00 00");
	BitVector<uint8_t> v6 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v6.toString().c_str(), "00 00 0");
	BitVector<uint8_t> v7 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v7.toString().c_str(), "00 00 00");
	EXPECT_THROW(BitVector<uint8_t>(0), std::invalid_argument);
}


TEST(BITVECTOR_1, INT64_T) {
	BitVector<int64_t> v1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "0000000000000000");
	BitVector<int64_t> v2 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "0000000000000000 0000000000000000");
	BitVector<int64_t> v3 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v3.toString().c_str(), "0000000000000000 0000000000000000 0000000000000000 0000000000000000");
	BitVector<int64_t> v4 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v4.toString().c_str(), "0000000000000000 0000000000000000 0");
	BitVector<int64_t> v5 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 - 1);
	EXPECT_STREQ(v5.toString().c_str(), "0000000000000000 0000000000000000 0000000000000000");
	BitVector<int64_t> v6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v6.toString().c_str(), "0000000000000000 0000000000000000 0");
	BitVector<int64_t> v7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v7.toString().c_str(), "0000000000000000 0000000000000000 00");
	EXPECT_THROW(BitVector<int64_t>(0), std::invalid_argument);
}


TEST(BITVECTOR_1, UINT64_T) {
	BitVector<uint64_t> v1 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "0000000000000000");
	BitVector<uint64_t> v2 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "0000000000000000 0000000000000000");
	BitVector<uint64_t> v3 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v3.toString().c_str(), "0000000000000000 0000000000000000 0000000000000000 0000000000000000");
	BitVector<uint64_t> v4 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v4.toString().c_str(), "0000000000000000 0000000000000000 0");
	BitVector<uint64_t> v5 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 3 - 1);
	EXPECT_STREQ(v5.toString().c_str(), "0000000000000000 0000000000000000 0000000000000000");
	BitVector<uint64_t> v6 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v6.toString().c_str(), "0000000000000000 0000000000000000 0");
	BitVector<uint64_t> v7 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v7.toString().c_str(), "0000000000000000 0000000000000000 00");
	EXPECT_THROW(BitVector<uint64_t>(0), std::invalid_argument);
}


TEST(BITVECTOR_2, INT8_T) {
	int8_t bits[] = {59, -1, 13, -6};
	BitVector<int8_t> v1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, bits);
	EXPECT_STREQ(v1.toString().c_str(), "3b");
	BitVector<int8_t> v2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(v2.toString().c_str(), "3b ff");
	BitVector<int8_t> v3 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3, bits);
	EXPECT_STREQ(v3.toString().c_str(), "3b ff 0d");
	BitVector<int8_t> v4 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(v4.toString().c_str(), "3b ff 0d fa");
	BitVector<int8_t> v5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 4, bits);
	EXPECT_STREQ(v5.toString().c_str(), "3b ff d");
	BitVector<int8_t> v6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(v6.toString().c_str(), "3b ff 1");
	BitVector<int8_t> v7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	EXPECT_STREQ(v7.toString().c_str(), "3b ff 5");
	BitVector<int8_t> v8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 5, bits);
	EXPECT_STREQ(v8.toString().c_str(), "3b ff 0d");
	BitVector<int8_t> v9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 4, bits);
	EXPECT_STREQ(v9.toString().c_str(), "3b ff 0d a");
	BitVector<int8_t> v10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(v10.toString().c_str(), "3b ff 0d 7a");
	EXPECT_THROW(BitVector<int8_t>(0, bits), std::invalid_argument);
}


TEST(BITVECTOR_2, UINT8_T) {
	uint8_t bits[] = {59, (uint8_t) -1, 13, (uint8_t) -6};
	BitVector<uint8_t> v1 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, bits);
	EXPECT_STREQ(v1.toString().c_str(), "3b");
	BitVector<uint8_t> v2 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(v2.toString().c_str(), "3b ff");
	BitVector<uint8_t> v3 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 3, bits);
	EXPECT_STREQ(v3.toString().c_str(), "3b ff 0d");
	BitVector<uint8_t> v4 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(v4.toString().c_str(), "3b ff 0d fa");
	BitVector<uint8_t> v5 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4, bits);
	EXPECT_STREQ(v5.toString().c_str(), "3b ff d");
	BitVector<uint8_t> v6 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(v6.toString().c_str(), "3b ff 1");
	BitVector<uint8_t> v7 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3, bits);
	EXPECT_STREQ(v7.toString().c_str(), "3b ff 5");
	BitVector<uint8_t> v8 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 5, bits);
	EXPECT_STREQ(v8.toString().c_str(), "3b ff 0d");
	BitVector<uint8_t> v9 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4 - 4, bits);
	EXPECT_STREQ(v9.toString().c_str(), "3b ff 0d a");
	BitVector<uint8_t> v10 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(v10.toString().c_str(), "3b ff 0d 7a");
	EXPECT_THROW(BitVector<uint8_t>(0, bits), std::invalid_argument);
}


TEST(BITVECTOR_2, INT64_T) {
	int64_t bits[] = {59, -1, 13, -6};
	BitVector<int64_t> v1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, bits);
	EXPECT_STREQ(v1.toString().c_str(), "000000000000003b");
	BitVector<int64_t> v2 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(v2.toString().c_str(), "000000000000003b ffffffffffffffff");
	BitVector<int64_t> v3 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3, bits);
	EXPECT_STREQ(v3.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d");
	BitVector<int64_t> v4 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(v4.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d fffffffffffffffa");
	BitVector<int64_t> v5 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 4, bits);
	EXPECT_STREQ(v5.toString().c_str(), "000000000000003b ffffffffffffffff d");
	BitVector<int64_t> v6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(v6.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<int64_t> v7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 3, bits);
	EXPECT_STREQ(v7.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<int64_t> v8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 5, bits);
	EXPECT_STREQ(v8.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<int64_t> v9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 4, bits);
	EXPECT_STREQ(v9.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d ffffffffffffffa");
	BitVector<int64_t> v10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(v10.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 7ffffffffffffffa");
	EXPECT_THROW(BitVector<int64_t>(0, bits), std::invalid_argument);
}


TEST(BITVECTOR_2, UINT64_T) {
	uint64_t bits[] = {59, (uint64_t) -1, 13, (uint64_t) -6};
	BitVector<uint64_t> v1 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, bits);
	EXPECT_STREQ(v1.toString().c_str(), "000000000000003b");
	BitVector<uint64_t> v2 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(v2.toString().c_str(), "000000000000003b ffffffffffffffff");
	BitVector<uint64_t> v3 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 3, bits);
	EXPECT_STREQ(v3.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d");
	BitVector<uint64_t> v4 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(v4.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d fffffffffffffffa");
	BitVector<uint64_t> v5 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4, bits);
	EXPECT_STREQ(v5.toString().c_str(), "000000000000003b ffffffffffffffff d");
	BitVector<uint64_t> v6 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(v6.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<uint64_t> v7 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3, bits);
	EXPECT_STREQ(v7.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<uint64_t> v8 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 5, bits);
	EXPECT_STREQ(v8.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<uint64_t> v9 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4 - 4, bits);
	EXPECT_STREQ(v9.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d ffffffffffffffa");
	BitVector<uint64_t> v10 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(v10.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 7ffffffffffffffa");
	EXPECT_THROW(BitVector<uint64_t>(0, bits), std::invalid_argument);
}


TEST(BITVECTOR_3, INT8_T) {
	int8_t bits[] = {59, -1, 13, -6};
	BitVector<int8_t> v1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, bits, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "3b");
	BitVector<int8_t> v2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "3b ff");
	BitVector<int8_t> v3 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3, bits, sizeof(int8_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v3.toString().c_str(), "3b ff 0d");
	BitVector<int8_t> v4 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits, sizeof(int8_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v4.toString().c_str(), "3b ff 0d fa");
	BitVector<int8_t> v5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v5.toString().c_str(), "3b ff d");
	BitVector<int8_t> v6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v6.toString().c_str(), "3b ff 1");
	BitVector<int8_t> v7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v7.toString().c_str(), "3b ff 5");
	BitVector<int8_t> v8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 5, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v8.toString().c_str(), "3b ff 0d");
	BitVector<int8_t> v9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 4, bits, sizeof(int8_t) * BITS_IN_BYTE * 4 - 4);
	EXPECT_STREQ(v9.toString().c_str(), "3b ff 0d a");
	BitVector<int8_t> v10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits, sizeof(int8_t) * BITS_IN_BYTE * 4 - 1);
	EXPECT_STREQ(v10.toString().c_str(), "3b ff 0d 7a");
	EXPECT_THROW(BitVector<int8_t>(0, bits, 1), std::invalid_argument);
	EXPECT_THROW(BitVector<int8_t>(1, bits, 0), std::invalid_argument);
	EXPECT_THROW(BitVector<int8_t>(1, bits, 2), std::invalid_argument);
	BitVector<int8_t> v11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE + 1);
	EXPECT_STREQ(v11.toString().c_str(), "3b 01");
	BitVector<int8_t> v12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE + 3);
	EXPECT_STREQ(v12.toString().c_str(), "3b 07");
	BitVector<int8_t> v13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE + 5);
	EXPECT_STREQ(v13.toString().c_str(), "3b 1f");
	BitVector<int8_t> v14 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v14.toString().c_str(), "3b 7f");
	BitVector<int8_t> v15 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(int8_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v15.toString().c_str(), "3b 7f 0");
	BitVector<int8_t> v16 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v16.toString().c_str(), "3b ff 0");
	BitVector<int8_t> v17 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v17.toString().c_str(), "3b ff 1");
	BitVector<int8_t> v18 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v18.toString().c_str(), "3b ff 5");
	BitVector<int8_t> v19 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 7, bits, sizeof(int8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v19.toString().c_str(), "3b ff 0d");
	BitVector<int8_t> v20 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits, sizeof(int8_t) * BITS_IN_BYTE * 3 + 2);
	EXPECT_STREQ(v20.toString().c_str(), "3b ff 0d 2");
}


TEST(BITVECTOR_3, UINT8_T) {
	uint8_t bits[] = {59, (uint8_t) -1, 13, (uint8_t) -6};
	BitVector<uint8_t> v1 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, bits, sizeof(uint8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "3b");
	BitVector<uint8_t> v2 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "3b ff");
	BitVector<uint8_t> v3 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 3, bits, sizeof(uint8_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v3.toString().c_str(), "3b ff 0d");
	BitVector<uint8_t> v4 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4, bits, sizeof(uint8_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v4.toString().c_str(), "3b ff 0d fa");
	BitVector<uint8_t> v5 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v5.toString().c_str(), "3b ff d");
	BitVector<uint8_t> v6 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v6.toString().c_str(), "3b ff 1");
	BitVector<uint8_t> v7 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v7.toString().c_str(), "3b ff 5");
	BitVector<uint8_t> v8 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 5, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v8.toString().c_str(), "3b ff 0d");
	BitVector<uint8_t> v9 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4 - 4, bits, sizeof(uint8_t) * BITS_IN_BYTE * 4 - 4);
	EXPECT_STREQ(v9.toString().c_str(), "3b ff 0d a");
	BitVector<uint8_t> v10 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 4 - 1, bits, sizeof(uint8_t) * BITS_IN_BYTE * 4 - 1);
	EXPECT_STREQ(v10.toString().c_str(), "3b ff 0d 7a");
	EXPECT_THROW(BitVector<uint8_t>(0, bits, 1), std::invalid_argument);
	EXPECT_THROW(BitVector<uint8_t>(1, bits, 0), std::invalid_argument);
	EXPECT_THROW(BitVector<uint8_t>(1, bits, 2), std::invalid_argument);
	BitVector<uint8_t> v11 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits, sizeof(uint8_t) * BITS_IN_BYTE + 1);
	EXPECT_STREQ(v11.toString().c_str(), "3b 01");
	BitVector<uint8_t> v12 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits, sizeof(uint8_t) * BITS_IN_BYTE + 3);
	EXPECT_STREQ(v12.toString().c_str(), "3b 07");
	BitVector<uint8_t> v13 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits, sizeof(uint8_t) * BITS_IN_BYTE + 5);
	EXPECT_STREQ(v13.toString().c_str(), "3b 1f");
	BitVector<uint8_t> v14 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2, bits, sizeof(uint8_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v14.toString().c_str(), "3b 7f");
	BitVector<uint8_t> v15 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(uint8_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v15.toString().c_str(), "3b 7f 0");
	BitVector<uint8_t> v16 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v16.toString().c_str(), "3b ff 0");
	BitVector<uint8_t> v17 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v17.toString().c_str(), "3b ff 1");
	BitVector<uint8_t> v18 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v18.toString().c_str(), "3b ff 5");
	BitVector<uint8_t> v19 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 2 + 7, bits, sizeof(uint8_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v19.toString().c_str(), "3b ff 0d");
	BitVector<uint8_t> v20 = BitVector<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE * 3 + 3, bits, sizeof(uint8_t) * BITS_IN_BYTE * 3 + 2);
	EXPECT_STREQ(v20.toString().c_str(), "3b ff 0d 2");
}


TEST(BITVECTOR_3, INT64_T) {
	int64_t bits[] = {59, -1, 13, -6};
	BitVector<int64_t> v1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, bits, sizeof(int64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "000000000000003b");
	BitVector<int64_t> v2 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits, sizeof(int64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "000000000000003b ffffffffffffffff");
	BitVector<int64_t> v3 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3, bits, sizeof(int64_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v3.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d");
	BitVector<int64_t> v4 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits, sizeof(int64_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v4.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d fffffffffffffffa");
	BitVector<int64_t> v5 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v5.toString().c_str(), "000000000000003b ffffffffffffffff d");
	BitVector<int64_t> v6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v6.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<int64_t> v7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v7.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<int64_t> v8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 5, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v8.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<int64_t> v9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 4, bits, sizeof(int64_t) * BITS_IN_BYTE * 4 - 4);
	EXPECT_STREQ(v9.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d ffffffffffffffa");
	BitVector<int64_t> v10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits, sizeof(int64_t) * BITS_IN_BYTE * 4 - 1);
	EXPECT_STREQ(v10.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 7ffffffffffffffa");
	EXPECT_THROW(BitVector<int64_t>(0, bits, 1), std::invalid_argument);
	EXPECT_THROW(BitVector<int64_t>(1, bits, 0), std::invalid_argument);
	EXPECT_THROW(BitVector<int64_t>(1, bits, 2), std::invalid_argument);
	BitVector<int64_t> v11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits, sizeof(int64_t) * BITS_IN_BYTE + 1);
	EXPECT_STREQ(v11.toString().c_str(), "000000000000003b 0000000000000001");
	BitVector<int64_t> v12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits, sizeof(int64_t) * BITS_IN_BYTE + 3);
	EXPECT_STREQ(v12.toString().c_str(), "000000000000003b 0000000000000007");
	BitVector<int64_t> v13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits, sizeof(int64_t) * BITS_IN_BYTE + 5);
	EXPECT_STREQ(v13.toString().c_str(), "000000000000003b 000000000000001f");
	BitVector<int64_t> v14 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits, sizeof(int64_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v14.toString().c_str(), "000000000000003b 000000000000007f");
	BitVector<int64_t> v15 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(int64_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v15.toString().c_str(), "000000000000003b 000000000000007f 0");
	BitVector<int64_t> v16 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v16.toString().c_str(), "000000000000003b ffffffffffffffff 0");
	BitVector<int64_t> v17 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v17.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<int64_t> v18 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v18.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<int64_t> v19 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 7, bits, sizeof(int64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v19.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<int64_t> v20 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits, sizeof(int64_t) * BITS_IN_BYTE * 3 + 2);
	EXPECT_STREQ(v20.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 2");
}


TEST(BITVECTOR_3, UINT64_T) {
	uint64_t bits[] = {59, (uint64_t) -1, 13, (uint64_t) -6};
	BitVector<uint64_t> v1 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, bits, sizeof(uint64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v1.toString().c_str(), "000000000000003b");
	BitVector<uint64_t> v2 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v2.toString().c_str(), "000000000000003b ffffffffffffffff");
	BitVector<uint64_t> v3 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 3, bits, sizeof(uint64_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v3.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d");
	BitVector<uint64_t> v4 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4, bits, sizeof(uint64_t) * BITS_IN_BYTE * 4);
	EXPECT_STREQ(v4.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d fffffffffffffffa");
	BitVector<uint64_t> v5 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v5.toString().c_str(), "000000000000003b ffffffffffffffff d");
	BitVector<uint64_t> v6 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v6.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<uint64_t> v7 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v7.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<uint64_t> v8 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 5, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 5);
	EXPECT_STREQ(v8.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<uint64_t> v9 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4 - 4, bits, sizeof(uint64_t) * BITS_IN_BYTE * 4 - 4);
	EXPECT_STREQ(v9.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d ffffffffffffffa");
	BitVector<uint64_t> v10 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 4 - 1, bits, sizeof(uint64_t) * BITS_IN_BYTE * 4 - 1);
	EXPECT_STREQ(v10.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 7ffffffffffffffa");
	EXPECT_THROW(BitVector<uint64_t>(0, bits, 1), std::invalid_argument);
	EXPECT_THROW(BitVector<uint64_t>(1, bits, 0), std::invalid_argument);
	EXPECT_THROW(BitVector<uint64_t>(1, bits, 2), std::invalid_argument);
	BitVector<uint64_t> v11 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits, sizeof(uint64_t) * BITS_IN_BYTE + 1);
	EXPECT_STREQ(v11.toString().c_str(), "000000000000003b 0000000000000001");
	BitVector<uint64_t> v12 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits, sizeof(uint64_t) * BITS_IN_BYTE + 3);
	EXPECT_STREQ(v12.toString().c_str(), "000000000000003b 0000000000000007");
	BitVector<uint64_t> v13 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits, sizeof(uint64_t) * BITS_IN_BYTE + 5);
	EXPECT_STREQ(v13.toString().c_str(), "000000000000003b 000000000000001f");
	BitVector<uint64_t> v14 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2, bits, sizeof(uint64_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v14.toString().c_str(), "000000000000003b 000000000000007f");
	BitVector<uint64_t> v15 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1, bits, sizeof(uint64_t) * BITS_IN_BYTE + 7);
	EXPECT_STREQ(v15.toString().c_str(), "000000000000003b 000000000000007f 0");
	BitVector<uint64_t> v16 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v16.toString().c_str(), "000000000000003b ffffffffffffffff 0");
	BitVector<uint64_t> v17 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 1);
	EXPECT_STREQ(v17.toString().c_str(), "000000000000003b ffffffffffffffff 1");
	BitVector<uint64_t> v18 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 3);
	EXPECT_STREQ(v18.toString().c_str(), "000000000000003b ffffffffffffffff 5");
	BitVector<uint64_t> v19 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 2 + 7, bits, sizeof(uint64_t) * BITS_IN_BYTE * 2 + 4);
	EXPECT_STREQ(v19.toString().c_str(), "000000000000003b ffffffffffffffff 0d");
	BitVector<uint64_t> v20 = BitVector<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE * 3 + 3, bits, sizeof(uint64_t) * BITS_IN_BYTE * 3 + 2);
	EXPECT_STREQ(v20.toString().c_str(), "000000000000003b ffffffffffffffff 000000000000000d 2");
}
