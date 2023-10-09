#pragma once


#include <stdlib.h>
#include <time.h>
#include "BitVector.hpp"


using namespace bv;


TEST(GETBIT, INT8_T) {
	EXPECT_EQ(getBit<int8_t>(10, 0), 0);
	EXPECT_EQ(getBit<int8_t>(10, 1), 1);
	EXPECT_EQ(getBit<int8_t>(10, 2), 0);
	EXPECT_EQ(getBit<int8_t>(10, 3), 1);
	EXPECT_EQ(getBit<int8_t>(10, sizeof(int8_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_EQ(getBit<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<int8_t>(10, sizeof(int8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<int8_t>(10, sizeof(int8_t) * BITS_IN_BYTE + 1), std::out_of_range);
}


TEST(GETBIT, UINT8_T) {
	EXPECT_EQ(getBit<uint8_t>(10, 0), 0);
	EXPECT_EQ(getBit<uint8_t>(10, 1), 1);
	EXPECT_EQ(getBit<uint8_t>(10, 2), 0);
	EXPECT_EQ(getBit<uint8_t>(10, 3), 1);
	EXPECT_EQ(getBit<uint8_t>(10, sizeof(uint8_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_EQ(getBit<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<uint8_t>(10, sizeof(uint8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<uint8_t>(10, sizeof(uint8_t) * BITS_IN_BYTE + 1), std::out_of_range);
}


TEST(GETBIT, INT64_T) {
	EXPECT_EQ(getBit<int64_t>(10, 0), 0);
	EXPECT_EQ(getBit<int64_t>(10, 1), 1);
	EXPECT_EQ(getBit<int64_t>(10, 2), 0);
	EXPECT_EQ(getBit<int64_t>(10, 3), 1);
	EXPECT_EQ(getBit<int64_t>(10, sizeof(int64_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_EQ(getBit<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<int64_t>(10, sizeof(int64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<int64_t>(10, sizeof(int64_t) * BITS_IN_BYTE + 1), std::out_of_range);
}


TEST(GETBIT, UINT64_T) {
	EXPECT_EQ(getBit<uint64_t>(10, 0), 0);
	EXPECT_EQ(getBit<uint64_t>(10, 1), 1);
	EXPECT_EQ(getBit<uint64_t>(10, 2), 0);
	EXPECT_EQ(getBit<uint64_t>(10, 3), 1);
	EXPECT_EQ(getBit<uint64_t>(10, sizeof(uint64_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_EQ(getBit<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_THROW(getBit<uint64_t>(10, sizeof(uint64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getBit<uint64_t>(10, sizeof(uint64_t) * BITS_IN_BYTE + 1), std::out_of_range);
}


TEST(SETBIT, INT8_T) {
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(0, 0, 1), 0), 1);
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(0, 1, 1), 1), 1);
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE - 1, 1), sizeof(int8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(-1, 0, 0), 0), 0);
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(-1, 1, 0), 1), 0);
	EXPECT_EQ(getBit<int8_t>(setBit<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 1, 0), sizeof(int8_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_THROW(setBit<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<int8_t>(0, sizeof(int8_t) * BITS_IN_BYTE + 1, 1), std::out_of_range);
}


TEST(SETBIT, UINT8_T) {
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>(0, 0, 1), 0), 1);
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>(0, 1, 1), 1), 1);
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE - 1, 1), sizeof(uint8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>((uint8_t) -1, 0, 0), 0), 0);
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>((uint8_t) -1, 1, 0), 1), 0);
	EXPECT_EQ(getBit<uint8_t>(setBit<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE - 1, 0), sizeof(uint8_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_THROW(setBit<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<uint8_t>(0, sizeof(uint8_t) * BITS_IN_BYTE + 1, 1), std::out_of_range);
}


TEST(SETBIT, INT64_T) {
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(0, 0, 1), 0), 1);
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(0, 1, 1), 1), 1);
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE - 1, 1), sizeof(int64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(-1, 0, 0), 0), 0);
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(-1, 1, 0), 1), 0);
	EXPECT_EQ(getBit<int64_t>(setBit<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 1, 0), sizeof(int64_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_THROW(setBit<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<int64_t>(0, sizeof(int64_t) * BITS_IN_BYTE + 1, 1), std::out_of_range);
}


TEST(SETBIT, UINT64_T) {
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>(0, 0, 1), 0), 1);
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>(0, 1, 1), 1), 1);
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE - 1, 1), sizeof(uint64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>((uint64_t) -1, 0, 0), 0), 0);
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>((uint64_t) -1, 1, 0), 1), 0);
	EXPECT_EQ(getBit<uint64_t>(setBit<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE - 1, 0), sizeof(uint64_t) * BITS_IN_BYTE - 1), 0);
	EXPECT_THROW(setBit<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(setBit<uint64_t>(0, sizeof(uint64_t) * BITS_IN_BYTE + 1, 1), std::out_of_range);
}


TEST(GETMASK, INT8_T) {
	EXPECT_EQ(getMask<int8_t>(0, 0), 0);
	EXPECT_EQ(getMask<int8_t>(1, 0), 1);
	EXPECT_EQ(getMask<int8_t>(3, 0), 7);
	EXPECT_EQ(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 0), -1);
	EXPECT_EQ(getMask<int8_t>(0, 1), 0);
	EXPECT_EQ(getMask<int8_t>(1, 1), 2);
	EXPECT_EQ(getMask<int8_t>(3, 3), 56);
	EXPECT_EQ(getMask<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE - 1), -128);
	EXPECT_THROW(getMask<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(2, sizeof(int8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(getMask<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, 2), std::out_of_range);
}


TEST(GETMASK, UINT8_T) {
	EXPECT_EQ(getMask<uint8_t>(0, 0), 0);
	EXPECT_EQ(getMask<uint8_t>(1, 0), 1);
	EXPECT_EQ(getMask<uint8_t>(3, 0), 7);
	EXPECT_EQ(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, 0), (uint8_t) -1);
	EXPECT_EQ(getMask<uint8_t>(0, 1), 0);
	EXPECT_EQ(getMask<uint8_t>(1, 1), 2);
	EXPECT_EQ(getMask<uint8_t>(3, 3), 56);
	EXPECT_EQ(getMask<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE - 1), (uint8_t) -128);
	EXPECT_THROW(getMask<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(2, sizeof(uint8_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(getMask<uint8_t>(sizeof(uint8_t) * BITS_IN_BYTE, 2), std::out_of_range);
}


TEST(GETMASK, INT64_T) {
	EXPECT_EQ(getMask<int64_t>(0, 0), 0);
	EXPECT_EQ(getMask<int64_t>(1, 0), 1);
	EXPECT_EQ(getMask<int64_t>(3, 0), 7);
	EXPECT_EQ(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 0), -1);
	EXPECT_EQ(getMask<int64_t>(0, 1), 0);
	EXPECT_EQ(getMask<int64_t>(1, 1), 2);
	EXPECT_EQ(getMask<int64_t>(3, 3), 56);
	EXPECT_EQ(getMask<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE - 2), 4611686018427387904);
	EXPECT_THROW(getMask<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(2, sizeof(int64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(getMask<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 2), std::out_of_range);
}


TEST(GETMASK, UINT64_T) {
	EXPECT_EQ(getMask<uint64_t>(0, 0), 0);
	EXPECT_EQ(getMask<uint64_t>(1, 0), 1);
	EXPECT_EQ(getMask<uint64_t>(3, 0), 7);
	EXPECT_EQ(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, 0), (uint64_t) -1);
	EXPECT_EQ(getMask<uint64_t>(0, 1), 0);
	EXPECT_EQ(getMask<uint64_t>(1, 1), 2);
	EXPECT_EQ(getMask<uint64_t>(3, 3), 56);
	EXPECT_EQ(getMask<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE - 2), 4611686018427387904);
	EXPECT_THROW(getMask<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(2, sizeof(uint64_t) * BITS_IN_BYTE), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, 1), std::out_of_range);
	EXPECT_THROW(getMask<uint64_t>(sizeof(uint64_t) * BITS_IN_BYTE, 2), std::out_of_range);
}

TEST(SETBITS_0, INT8_T) {
	int8_t bits[] = {-1, -1, -1, -1, -1};
	
	BitVector<int8_t> v1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	v1.setBits(sizeof(int8_t) * BITS_IN_BYTE, bits, 0);
	EXPECT_STREQ(v1.toString().c_str(), "ff");
	BitVector<int8_t> v2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v2.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, 0);
	EXPECT_STREQ(v2.toString().c_str(), "ff ff");
	BitVector<int8_t> v3 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v3.setBits(sizeof(int8_t) * BITS_IN_BYTE * 3, bits, 0);
	EXPECT_STREQ(v3.toString().c_str(), "ff ff ff 00");
	BitVector<int8_t> v4 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 + 1);
	v4.setBits(sizeof(int8_t) * BITS_IN_BYTE * 4, bits, 0);
	EXPECT_STREQ(v4.toString().c_str(), "ff ff ff ff 0");
	BitVector<int8_t> v5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 8 - 1);
	v5.setBits(sizeof(int8_t) * BITS_IN_BYTE * 5, bits, 0);
	EXPECT_STREQ(v5.toString().c_str(), "ff ff ff ff ff 00 00 00");
	
	BitVector<int8_t> v6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v6.setBits(sizeof(int8_t) * BITS_IN_BYTE, bits, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v6.toString().c_str(), "00 ff");
	BitVector<int8_t> v7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v7.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v7.toString().c_str(), "00 00 ff ff");
	BitVector<int8_t> v8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 5);
	v8.setBits(sizeof(int8_t) * BITS_IN_BYTE * 3, bits, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v8.toString().c_str(), "00 ff ff ff 00");
	BitVector<int8_t> v9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 7);
	v9.setBits(sizeof(int8_t) * BITS_IN_BYTE * 5, bits, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v9.toString().c_str(), "00 00 ff ff ff ff ff");
	BitVector<int8_t> v10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 8);
	v10.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2, bits, sizeof(int8_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v10.toString().c_str(), "00 00 00 ff ff 00 00 00");
	
	BitVector<int8_t> v11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	v11.setBits(0, bits, 0);
	EXPECT_STREQ(v11.toString().c_str(), "00");
	BitVector<int8_t> v12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3);
	v12.setBits(1, bits, 0);
	EXPECT_STREQ(v12.toString().c_str(), "01 00 00");
	BitVector<int8_t> v13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v13.setBits(3, bits, 0);
	EXPECT_STREQ(v13.toString().c_str(), "07 00");
	BitVector<int8_t> v14 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	v14.setBits(5, bits, 0);
	EXPECT_STREQ(v14.toString().c_str(), "1f");
	BitVector<int8_t> v15 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v15.setBits(7, bits, 0);
	EXPECT_STREQ(v15.toString().c_str(), "7f 00 00 00");
	
	BitVector<int8_t> v16 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v16.setBits(sizeof(int8_t) * BITS_IN_BYTE + 1, bits, 0);
	EXPECT_STREQ(v16.toString().c_str(), "ff 01");
	BitVector<int8_t> v17 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v17.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 0);
	EXPECT_STREQ(v17.toString().c_str(), "ff ff 07 00");
	BitVector<int8_t> v18 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v18.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 7, bits, 0);
	EXPECT_STREQ(v18.toString().c_str(), "ff ff 7f 00");
	BitVector<int8_t> v19 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v19.setBits(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits, 0);
	EXPECT_STREQ(v19.toString().c_str(), "ff ff ff 03");
	BitVector<int8_t> v20 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v20.setBits(sizeof(int8_t) * BITS_IN_BYTE * 3 - 3, bits, 0);
	EXPECT_STREQ(v20.toString().c_str(), "ff ff 1f 00");
	
	BitVector<int8_t> v21 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	v21.setBits(1, bits, 2);
	EXPECT_STREQ(v21.toString().c_str(), "04");
	BitVector<int8_t> v22 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v22.setBits(3, bits, 3);
	EXPECT_STREQ(v22.toString().c_str(), "38 00");
	BitVector<int8_t> v23 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3);
	v23.setBits(4, bits, 4);
	EXPECT_STREQ(v23.toString().c_str(), "f0 00 00");
	BitVector<int8_t> v24 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v24.setBits(1, bits, 4);
	EXPECT_STREQ(v24.toString().c_str(), "10 00");
	BitVector<int8_t> v25 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v25.setBits(2, bits, 5);
	EXPECT_STREQ(v25.toString().c_str(), "60 00 00 00");
	
	BitVector<int8_t> v26 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v26.setBits(sizeof(int8_t) * BITS_IN_BYTE + 1, bits, 1);
	EXPECT_STREQ(v26.toString().c_str(), "fe 03");
	BitVector<int8_t> v27 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	v27.setBits(sizeof(int8_t) * BITS_IN_BYTE, bits, 1);
	EXPECT_STREQ(v27.toString().c_str(), "fe 01");
	BitVector<int8_t> v28 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v28.setBits(sizeof(int8_t) * BITS_IN_BYTE + 3, bits, 3);
	EXPECT_STREQ(v28.toString().c_str(), "f8 3f 00 00");
	BitVector<int8_t> v29 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v29.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 5, bits, 7);
	EXPECT_STREQ(v29.toString().c_str(), "80 ff ff 0f");
	BitVector<int8_t> v30 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v30.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 2, bits, sizeof(int8_t) * BITS_IN_BYTE + 2);
	EXPECT_STREQ(v30.toString().c_str(), "00 fc ff 0f");
	
	BitVector<int8_t> v31 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v31.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 0);
	EXPECT_STREQ(v31.toString().c_str(), "ff ff 07 00");
	BitVector<int8_t> v32 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v32.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 1);
	EXPECT_STREQ(v32.toString().c_str(), "fe ff 0f 00");
	BitVector<int8_t> v33 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v33.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 2);
	EXPECT_STREQ(v33.toString().c_str(), "fc ff 1f 00");
	BitVector<int8_t> v34 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v34.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 3);
	EXPECT_STREQ(v34.toString().c_str(), "f8 ff 3f 00");
	BitVector<int8_t> v35 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v35.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 4);
	EXPECT_STREQ(v35.toString().c_str(), "f0 ff 7f 00");
	BitVector<int8_t> v36 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v36.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 5);
	EXPECT_STREQ(v36.toString().c_str(), "e0 ff ff 00");
	BitVector<int8_t> v37 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v37.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 6);
	EXPECT_STREQ(v37.toString().c_str(), "c0 ff ff 01");
	BitVector<int8_t> v38 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v38.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 7);
	EXPECT_STREQ(v38.toString().c_str(), "80 ff ff 03");
	BitVector<int8_t> v39 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	v39.setBits(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits, 8);
	EXPECT_STREQ(v39.toString().c_str(), "00 ff ff 07");
	
	BitVector<int8_t> v40 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	EXPECT_THROW(v40.setBits(sizeof(int8_t) * BITS_IN_BYTE * 4, bits, 1), std::out_of_range);
	EXPECT_THROW(v40.setBits(sizeof(int8_t) * BITS_IN_BYTE * 4, bits, 10), std::out_of_range);
	EXPECT_THROW(v40.setBits(1, bits, sizeof(int8_t) * BITS_IN_BYTE * 4), std::out_of_range);
	EXPECT_THROW(v40.setBits(10, bits, sizeof(int8_t) * BITS_IN_BYTE * 4), std::out_of_range);
}


TEST(SETBITS_1, INT8_T) {
	int8_t bits[] = {-1, -1, -1, -1, -1};
	
	BitVector<int8_t> v1 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	BitVector<int8_t> v1_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, bits);
	v1.setBits(v1_, 0);
	EXPECT_STREQ(v1.toString().c_str(), "ff");
	BitVector<int8_t> v2 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v2_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	v2.setBits(v2_, 0);
	EXPECT_STREQ(v2.toString().c_str(), "ff ff");
	BitVector<int8_t> v3 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v3_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3, bits);
	v3.setBits(v3_, 0);
	EXPECT_STREQ(v3.toString().c_str(), "ff ff ff 00");
	BitVector<int8_t> v4 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 + 1);
	BitVector<int8_t> v4_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	v4.setBits(v4_, 0);
	EXPECT_STREQ(v4.toString().c_str(), "ff ff ff ff 0");
	BitVector<int8_t> v5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 8 - 1);
	BitVector<int8_t> v5_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 5, bits);
	v5.setBits(v5_, 0);
	EXPECT_STREQ(v5.toString().c_str(), "ff ff ff ff ff 00 00 00");
	
	BitVector<int8_t> v6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v6_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, bits);
	v6.setBits(v6_, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v6.toString().c_str(), "00 ff");
	BitVector<int8_t> v7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v7_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	v7.setBits(v7_, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v7.toString().c_str(), "00 00 ff ff");
	BitVector<int8_t> v8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 5);
	BitVector<int8_t> v8_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3, bits);
	v8.setBits(v8_, sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(v8.toString().c_str(), "00 ff ff ff 00");
	BitVector<int8_t> v9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 7);
	BitVector<int8_t> v9_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 5, bits);
	v9.setBits(v9_, sizeof(int8_t) * BITS_IN_BYTE * 2);
	EXPECT_STREQ(v9.toString().c_str(), "00 00 ff ff ff ff ff");
	BitVector<int8_t> v10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 8);
	BitVector<int8_t> v10_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	v10.setBits(v10_, sizeof(int8_t) * BITS_IN_BYTE * 3);
	EXPECT_STREQ(v10.toString().c_str(), "00 00 00 ff ff 00 00 00");
	
	BitVector<int8_t> v12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3);
	BitVector<int8_t> v12_ = BitVector<int8_t>(1, bits);
	v12.setBits(v12_, 0);
	EXPECT_STREQ(v12.toString().c_str(), "01 00 00");
	BitVector<int8_t> v13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v13_ = BitVector<int8_t>(3, bits);
	v13.setBits(v13_, 0);
	EXPECT_STREQ(v13.toString().c_str(), "07 00");
	BitVector<int8_t> v14 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	BitVector<int8_t> v14_ = BitVector<int8_t>(5, bits);
	v14.setBits(v14_, 0);
	EXPECT_STREQ(v14.toString().c_str(), "1f");
	BitVector<int8_t> v15 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v15_ = BitVector<int8_t>(7, bits);
	v15.setBits(v15_, 0);
	EXPECT_STREQ(v15.toString().c_str(), "7f 00 00 00");
	
	BitVector<int8_t> v16 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v16_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE + 1, bits);
	v16.setBits(v16_, 0);
	EXPECT_STREQ(v16.toString().c_str(), "ff 01");
	BitVector<int8_t> v17 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v17_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v17.setBits(v17_, 0);
	EXPECT_STREQ(v17.toString().c_str(), "ff ff 07 00");
	BitVector<int8_t> v18 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v18_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 7, bits);
	v18.setBits(v18_, 0);
	EXPECT_STREQ(v18.toString().c_str(), "ff ff 7f 00");
	BitVector<int8_t> v19 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v19_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	v19.setBits(v19_, 0);
	EXPECT_STREQ(v19.toString().c_str(), "ff ff ff 03");
	BitVector<int8_t> v20 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v20_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 - 3, bits);
	v20.setBits(v20_, 0);
	EXPECT_STREQ(v20.toString().c_str(), "ff ff 1f 00");
	
	BitVector<int8_t> v21 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	BitVector<int8_t> v21_ = BitVector<int8_t>(1, bits);
	v21.setBits(v21_, 2);
	EXPECT_STREQ(v21.toString().c_str(), "04");
	BitVector<int8_t> v22 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v22_ = BitVector<int8_t>(3, bits);
	v22.setBits(v22_, 3);
	EXPECT_STREQ(v22.toString().c_str(), "38 00");
	BitVector<int8_t> v23 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3);
	BitVector<int8_t> v23_ = BitVector<int8_t>(4, bits);
	v23.setBits(v23_, 4);
	EXPECT_STREQ(v23.toString().c_str(), "f0 00 00");
	BitVector<int8_t> v24 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v24_ = BitVector<int8_t>(1, bits);
	v24.setBits(v24_, 4);
	EXPECT_STREQ(v24.toString().c_str(), "10 00");
	BitVector<int8_t> v25 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v25_ = BitVector<int8_t>(2, bits);
	v25.setBits(v25_, 5);
	EXPECT_STREQ(v25.toString().c_str(), "60 00 00 00");
	
	BitVector<int8_t> v26 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v26_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE + 1, bits);
	v26.setBits(v26_, 1);
	EXPECT_STREQ(v26.toString().c_str(), "fe 03");
	BitVector<int8_t> v27 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2);
	BitVector<int8_t> v27_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE, bits);
	v27.setBits(v27_, 1);
	EXPECT_STREQ(v27.toString().c_str(), "fe 01");
	BitVector<int8_t> v28 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v28_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE + 3, bits);
	v28.setBits(v28_, 3);
	EXPECT_STREQ(v28.toString().c_str(), "f8 3f 00 00");
	BitVector<int8_t> v29 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v29_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 5, bits);
	v29.setBits(v29_, 7);
	EXPECT_STREQ(v29.toString().c_str(), "80 ff ff 0f");
	BitVector<int8_t> v30 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v30_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 2, bits);
	v30.setBits(v30_, sizeof(int8_t) * BITS_IN_BYTE + 2);
	EXPECT_STREQ(v30.toString().c_str(), "00 fc ff 0f");
	
	BitVector<int8_t> v31 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v31_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v31.setBits(v31_, 0);
	EXPECT_STREQ(v31.toString().c_str(), "ff ff 07 00");
	BitVector<int8_t> v32 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v32_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v32.setBits(v32_, 1);
	EXPECT_STREQ(v32.toString().c_str(), "fe ff 0f 00");
	BitVector<int8_t> v33 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v33_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v33.setBits(v33_, 2);
	EXPECT_STREQ(v33.toString().c_str(), "fc ff 1f 00");
	BitVector<int8_t> v34 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v34_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v34.setBits(v34_, 3);
	EXPECT_STREQ(v34.toString().c_str(), "f8 ff 3f 00");
	BitVector<int8_t> v35 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v35_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v35.setBits(v35_, 4);
	EXPECT_STREQ(v35.toString().c_str(), "f0 ff 7f 00");
	BitVector<int8_t> v36 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v36_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v36.setBits(v36_, 5);
	EXPECT_STREQ(v36.toString().c_str(), "e0 ff ff 00");
	BitVector<int8_t> v37 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v37_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v37.setBits(v37_, 6);
	EXPECT_STREQ(v37.toString().c_str(), "c0 ff ff 01");
	BitVector<int8_t> v38 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v38_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v38.setBits(v38_, 7);
	EXPECT_STREQ(v38.toString().c_str(), "80 ff ff 03");
	BitVector<int8_t> v39 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v39_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 3, bits);
	v39.setBits(v39_, 8);
	EXPECT_STREQ(v39.toString().c_str(), "00 ff ff 07");
	
	BitVector<int8_t> v40 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4);
	BitVector<int8_t> v40_ = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int8_t> v40__ = BitVector<int8_t>(1, bits);
	EXPECT_THROW(v40.setBits(v40_, 1), std::out_of_range);
	EXPECT_THROW(v40.setBits(v40_, 10), std::out_of_range);
	EXPECT_THROW(v40.setBits(v40_, sizeof(int8_t) * BITS_IN_BYTE * 4), std::out_of_range);
}


TEST(GETBITS, INT8_T) {
	srand(time(NULL));
	int8_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int8_t) * BITS_IN_BYTE)) + 1;
		size_t size = std::rand() % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		BitVector<int8_t> v1 = BitVector<int8_t>(max_size, bits);
		BitVector<int8_t> v2 = BitVector<int8_t>(max_size, bits);
		int8_t *tmp = v1.getBits(size, offset);
		v2.setBits(size, tmp, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		delete[] tmp;
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<int8_t> v1 = BitVector<int8_t>(1, bits);
	EXPECT_THROW(v1.getBits(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(1, 10), std::out_of_range);
}


TEST(GETBITS, UINT8_T) {
	srand(time(NULL));
	uint8_t bits[] = {(uint8_t) -1, 127, (uint8_t) -128, (uint8_t) -1, 15, (uint8_t) -61, (uint8_t) -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(uint8_t) * BITS_IN_BYTE)) + 1;
		size_t size = std::rand() % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		BitVector<uint8_t> v1 = BitVector<uint8_t>(max_size, bits);
		BitVector<uint8_t> v2 = BitVector<uint8_t>(max_size, bits);
		uint8_t *tmp = v1.getBits(size, offset);
		v2.setBits(size, tmp, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		delete[] tmp;
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<uint8_t> v1 = BitVector<uint8_t>(1, bits);
	EXPECT_THROW(v1.getBits(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(1, 10), std::out_of_range);
}


TEST(GETBITS, INT64_T) {
	srand(time(NULL));
	int64_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int64_t) * BITS_IN_BYTE)) + 1;
		size_t size = std::rand() % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		BitVector<int64_t> v1 = BitVector<int64_t>(max_size, bits);
		BitVector<int64_t> v2 = BitVector<int64_t>(max_size, bits);
		int64_t *tmp = v1.getBits(size, offset);
		v2.setBits(size, tmp, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		delete[] tmp;
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<int64_t> v1 = BitVector<int64_t>(1, bits);
	EXPECT_THROW(v1.getBits(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(1, 10), std::out_of_range);
}


TEST(GETBITS, UINT64_T) {
	srand(time(NULL));
	uint64_t bits[] = {(uint64_t) -1, 127, (uint64_t) -128, (uint64_t) -1, 15, (uint64_t) -61, (uint64_t) -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(uint64_t) * BITS_IN_BYTE)) + 1;
		size_t size = std::rand() % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		BitVector<uint64_t> v1 = BitVector<uint64_t>(max_size, bits);
		BitVector<uint64_t> v2 = BitVector<uint64_t>(max_size, bits);
		uint64_t *tmp = v1.getBits(size, offset);
		v2.setBits(size, tmp, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		delete[] tmp;
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<uint64_t> v1 = BitVector<uint64_t>(1, bits);
	EXPECT_THROW(v1.getBits(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getBits(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, INT8_T) {
	srand(time(NULL));
	int8_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int8_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(int8_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<int8_t> v1 = BitVector<int8_t>(max_size, bits);
		BitVector<int8_t> v2 = BitVector<int8_t>(max_size, bits);
		int8_t tmp_1 = v1.getFewBits<int8_t>(size, offset);
		int8_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<int8_t> v1 = BitVector<int8_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<int8_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int8_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int8_t>(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, UINT8_T) {
	srand(time(NULL));
	uint8_t bits[] = {(uint8_t) -1, 127, (uint8_t) -128, (uint8_t) -1, 15, (uint8_t) -61, (uint8_t) -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(uint8_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(uint8_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<uint8_t> v1 = BitVector<uint8_t>(max_size, bits);
		BitVector<uint8_t> v2 = BitVector<uint8_t>(max_size, bits);
		uint8_t tmp_1 = v1.getFewBits<uint8_t>(size, offset);
		uint8_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<uint8_t> v1 = BitVector<uint8_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<uint8_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<uint8_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<uint8_t>(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, INT64_T) {
	srand(time(NULL));
	int64_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int64_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(int64_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<int64_t> v1 = BitVector<int64_t>(max_size, bits);
		BitVector<int64_t> v2 = BitVector<int64_t>(max_size, bits);
		int64_t tmp_1 = v1.getFewBits<int64_t>(size, offset);
		int64_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<int64_t> v1 = BitVector<int64_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<int64_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int64_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int64_t>(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, UINT64_T) {
	srand(time(NULL));
	uint64_t bits[] = {(uint64_t) -1, 127, (uint64_t) -128, (uint64_t) -1, 15, (uint64_t) -61, (uint64_t) -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(uint64_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(uint64_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<uint64_t> v1 = BitVector<uint64_t>(max_size, bits);
		BitVector<uint64_t> v2 = BitVector<uint64_t>(max_size, bits);
		uint64_t tmp_1 = v1.getFewBits<uint64_t>(size, offset);
		uint64_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<uint64_t> v1 = BitVector<uint64_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<uint64_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<uint64_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<uint64_t>(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, INT8_T_INT64_T) {
	srand(time(NULL));
	int8_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int8_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(int8_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<int8_t> v1 = BitVector<int8_t>(max_size, bits);
		BitVector<int8_t> v2 = BitVector<int8_t>(max_size, bits);
		int8_t tmp_1 = v1.getFewBits<int64_t>(size, offset);
		int8_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	int8_t bits_[] = {-1, -1, -1, -1, -1, -1, -1, -1};
	BitVector<int8_t> v = BitVector<int8_t>(8 * sizeof(int8_t) * BITS_IN_BYTE, bits_);
	int64_t tmp = v.getFewBits<int64_t>(sizeof(int64_t) * BITS_IN_BYTE, 0);
	EXPECT_EQ(tmp, -1);
	BitVector<int8_t> v1 = BitVector<int8_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<int64_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int64_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int64_t>(1, 10), std::out_of_range);
}


TEST(GETFEWBITS, INT64_T_INT8_T) {
	srand(time(NULL));
	int64_t bits[] = {-1, 127, -128, -1, 15, -61, -17, 9};
	int iter_c = 1000;
	for (int i = 0; i < iter_c; i++) {
		size_t max_size = (std::rand() % (8 * sizeof(int64_t) * BITS_IN_BYTE)) + 1;
		size_t size = (std::rand() % (sizeof(int8_t) * BITS_IN_BYTE + 1)) % (max_size + 1);
		size_t offset = std::rand() % (max_size - size + 1);
		//std::cout << "DATA: " << max_size << " " << size << " " << offset << std::endl;
		BitVector<int64_t> v1 = BitVector<int64_t>(max_size, bits);
		BitVector<int64_t> v2 = BitVector<int64_t>(max_size, bits);
		int64_t tmp_1 = v1.getFewBits<int8_t>(size, offset);
		int64_t tmp_2[1] = {tmp_1};
		v2.setBits(size, tmp_2, offset);
		EXPECT_STREQ(v1.toString().c_str(), v2.toString().c_str());
		//std::cout << "V1: " << v1.toString() << std::endl;
		//std::cout << "V2: " << v2.toString() << std::endl;
	}
	BitVector<int64_t> v1 = BitVector<int64_t>(1, bits);
	EXPECT_THROW(v1.getFewBits<int8_t>(1, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int8_t>(10, 1), std::out_of_range);
	EXPECT_THROW(v1.getFewBits<int8_t>(1, 10), std::out_of_range);
}
