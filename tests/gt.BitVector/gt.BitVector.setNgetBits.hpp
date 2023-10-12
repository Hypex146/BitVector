#pragma once


#include "BitVector.hpp"


using namespace bv;


TEST(SETBITS_0, INT8) {
	int8_t bits1[] = {0, 0};
	int8_t bits2[] = {-1, -1};
	int8_t bits3[] = {16, 8};
	int8_t bits4[] = {7, 5};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits1);
	bv1.setBits(1, bits2, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "0001");
	bv1.setBits(3, bits2, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "000f");
	bv1.setBits(1, bits2, 4);
	EXPECT_STREQ(bv1.toString().c_str(), "001f");
	bv1.setBits(sizeof(int8_t) * BITS_IN_BYTE, bits2, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(bv1.toString().c_str(), "ff1f");
	bv1.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2, bits1, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "0000");
	bv1.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2, bits3, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "1008");
	bv1.setBits(sizeof(int8_t) * BITS_IN_BYTE * 1 + 2, bits4, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "1305");
}


TEST(SETBITS_0, INT64) {
	int64_t bits1[] = {0, 0};
	int64_t bits2[] = {-1, -1};
	int64_t bits3[] = {16, 8};
	int64_t bits4[] = {7, 5};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits1);
	bv1.setBits(1, bits2, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "00000000000000000000000000000001");
	bv1.setBits(3, bits2, 1);
	EXPECT_STREQ(bv1.toString().c_str(), "0000000000000000000000000000000f");
	bv1.setBits(1, bits2, 4);
	EXPECT_STREQ(bv1.toString().c_str(), "0000000000000000000000000000001f");
	bv1.setBits(sizeof(int64_t) * BITS_IN_BYTE, bits2, sizeof(int64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(bv1.toString().c_str(), "ffffffffffffffff000000000000001f");
	bv1.setBits(sizeof(int64_t) * BITS_IN_BYTE * 2, bits1, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "00000000000000000000000000000000");
	bv1.setBits(sizeof(int64_t) * BITS_IN_BYTE * 2, bits3, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "00000000000000100000000000000008");
	bv1.setBits(sizeof(int64_t) * BITS_IN_BYTE * 1 + 2, bits4, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "00000000000000130000000000000005");
}


TEST(SETBITS_1, INT8) {
	int8_t bits1[] = {0, 0};
	int8_t bits2[] = {-1, -1};
	int8_t bits3[] = {16, 8};
	int8_t bits4[] = {7, 5};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits1);
	BitVector<int8_t> bv2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 1, bits2);
	bv1.setBits(bv2, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "00ff");
	bv1.setBits(bv2, 4);
	EXPECT_STREQ(bv1.toString().c_str(), "0fff");
	bv1.setBits(bv2, 5);
	EXPECT_STREQ(bv1.toString().c_str(), "1fff");
}


TEST(SETBITS_1, INT64) {
	int64_t bits1[] = {0, 0};
	int64_t bits2[] = {-1, -1};
	int64_t bits3[] = {16, 8};
	int64_t bits4[] = {7, 5};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits1);
	BitVector<int64_t> bv2 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 1, bits2);
	bv1.setBits(bv2, 0);
	EXPECT_STREQ(bv1.toString().c_str(), "0000000000000000ffffffffffffffff");
	bv1.setBits(bv2, 4);
	EXPECT_STREQ(bv1.toString().c_str(), "000000000000000fffffffffffffffff");
	bv1.setBits(bv2, 5);
	EXPECT_STREQ(bv1.toString().c_str(), "000000000000001fffffffffffffffff");
}


TEST(GETBITS, INT8) {
	int8_t bits[] = {87, 10};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int8_t> bv2;
	bv2 = bv1.getBits(1, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	bv2 = bv1.getBits(1, 1);
	EXPECT_STREQ(bv2.toString().c_str(), "1");
	bv2 = bv1.getBits(1, 2);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	bv2 = bv1.getBits(1, 3);
	EXPECT_STREQ(bv2.toString().c_str(), "1");
	bv2 = bv1.getBits(4, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "a");
	bv2 = bv1.getBits(7, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "0a");
	bv2 = bv1.getBits(sizeof(int8_t) * BITS_IN_BYTE, (sizeof(int8_t) * BITS_IN_BYTE) / 2);
	EXPECT_STREQ(bv2.toString().c_str(), "70");
	bv2 = bv1.getBits(sizeof(int8_t) * BITS_IN_BYTE, (sizeof(int8_t) * BITS_IN_BYTE) / 2 + 1);
	EXPECT_STREQ(bv2.toString().c_str(), "b8");
	bv2 = bv1.getBits(sizeof(int8_t) * BITS_IN_BYTE * 2, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "570a");
}


TEST(GETBITS, INT64) {
	int64_t bits[] = {87, 10};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int64_t> bv2;
	bv2 = bv1.getBits(1, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	bv2 = bv1.getBits(1, 1);
	EXPECT_STREQ(bv2.toString().c_str(), "1");
	bv2 = bv1.getBits(1, 2);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	bv2 = bv1.getBits(1, 3);
	EXPECT_STREQ(bv2.toString().c_str(), "1");
	bv2 = bv1.getBits(4, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "a");
	bv2 = bv1.getBits(7, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "0a");
	bv2 = bv1.getBits(sizeof(int64_t) * BITS_IN_BYTE, (sizeof(int64_t) * BITS_IN_BYTE) / 2);
	EXPECT_STREQ(bv2.toString().c_str(), "0000005700000000");
	bv2 = bv1.getBits(sizeof(int64_t) * BITS_IN_BYTE, (sizeof(int64_t) * BITS_IN_BYTE) / 2 + 1);
	EXPECT_STREQ(bv2.toString().c_str(), "0000002b80000000");
	bv2 = bv1.getBits(sizeof(int64_t) * BITS_IN_BYTE * 2, 0);
	EXPECT_STREQ(bv2.toString().c_str(), "0000000000000057000000000000000a");
}


TEST(GETBITS, INT8_INT8) {
	int8_t bits[] = {87, 10};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(1, 0)).c_str(), "00");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(4, 0)).c_str(), "0a");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(2, 2)).c_str(), "02");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 0)).c_str(), "0a");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 2, 2)).c_str(), "02");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, sizeof(int8_t) * BITS_IN_BYTE)).c_str(), "57");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 1, sizeof(int8_t) * BITS_IN_BYTE + 1)).c_str(), "2b");
}


TEST(GETBITS, INT8_INT64) {
	int8_t bits[] = {87, 10};
	BitVector<int8_t> bv1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(1, 0)).c_str(), "0000000000000000");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(4, 0)).c_str(), "000000000000000a");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(2, 2)).c_str(), "0000000000000002");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int8_t) * BITS_IN_BYTE, 0)).c_str(), "000000000000000a");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int8_t) * BITS_IN_BYTE - 2, 2)).c_str(), "0000000000000002");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int8_t) * BITS_IN_BYTE, sizeof(int8_t) * BITS_IN_BYTE)).c_str(), "0000000000000057");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int8_t) * BITS_IN_BYTE - 1, sizeof(int8_t) * BITS_IN_BYTE + 1)).c_str(), "000000000000002b");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, 0)).c_str(), "000000000000570a");
}


TEST(GETBITS, INT64_INT64) {
	int64_t bits[] = {87, 10};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(1, 0)).c_str(), "0000000000000000");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(4, 0)).c_str(), "000000000000000a");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(2, 2)).c_str(), "0000000000000002");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 0)).c_str(), "000000000000000a");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int64_t) * BITS_IN_BYTE - 2, 2)).c_str(), "0000000000000002");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, sizeof(int64_t) * BITS_IN_BYTE)).c_str(), "0000000000000057");
	EXPECT_STREQ(toHex<int64_t>(bv1.getFewBits<int64_t>(sizeof(int64_t) * BITS_IN_BYTE - 1, sizeof(int64_t) * BITS_IN_BYTE + 1)).c_str(), "000000000000002b");
}


TEST(GETBITS, INT64_INT8) {
	int64_t bits[] = {87, 10};
	BitVector<int64_t> bv1 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(1, 0)).c_str(), "00");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(4, 0)).c_str(), "0a");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(2, 2)).c_str(), "02");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 0)).c_str(), "0a");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 2, 2)).c_str(), "02");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, sizeof(int64_t) * BITS_IN_BYTE)).c_str(), "57");
	EXPECT_STREQ(toHex<int8_t>(bv1.getFewBits<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 1, sizeof(int64_t) * BITS_IN_BYTE + 1)).c_str(), "2b");
}
	