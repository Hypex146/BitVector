#pragma once


#include "BitVector.hpp"


using namespace bv;


template <std::integral IntType>
BitVector<IntType> moveTestConstr(const BitVector<IntType> &bit_vector) {
	return bit_vector;
}


TEST(BITVECTOR_0, INT8) {
	BitVector<int8_t> bv1 = BitVector<int8_t>();
	EXPECT_STREQ(bv1.toString().c_str(), "00");
}


TEST(BITVECTOR_0, INT64) {
	BitVector<int64_t> bv1 = BitVector<int64_t>();
	EXPECT_STREQ(bv1.toString().c_str(), "0000000000000000");
}


TEST(BITVECTOR_1, INT8) {
	BitVector<int8_t> bv1 = BitVector<int8_t>(1);
	EXPECT_STREQ(bv1.toString().c_str(), "0");
	BitVector<int8_t> bv2 = BitVector<int8_t>(4);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	BitVector<int8_t> bv3 = BitVector<int8_t>(5);
	EXPECT_STREQ(bv3.toString().c_str(), "00");
	BitVector<int8_t> bv4 = BitVector<int8_t>(8);
	EXPECT_STREQ(bv4.toString().c_str(), "00");
	BitVector<int8_t> bv5 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 4);
	EXPECT_STREQ(bv5.toString().c_str(), "0");
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE - 1);
	EXPECT_STREQ(bv6.toString().c_str(), "00");
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE);
	EXPECT_STREQ(bv7.toString().c_str(), "00");
}


TEST(BITVECTOR_1, INT64) {
	BitVector<int64_t> bv1 = BitVector<int64_t>(1);
	EXPECT_STREQ(bv1.toString().c_str(), "0");
	BitVector<int64_t> bv2 = BitVector<int64_t>(4);
	EXPECT_STREQ(bv2.toString().c_str(), "0");
	BitVector<int64_t> bv3 = BitVector<int64_t>(5);
	EXPECT_STREQ(bv3.toString().c_str(), "00");
	BitVector<int64_t> bv4 = BitVector<int64_t>(8);
	EXPECT_STREQ(bv4.toString().c_str(), "00");
	BitVector<int64_t> bv5 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE - 4);
	EXPECT_STREQ(bv5.toString().c_str(), "000000000000000");
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE - 1);
	EXPECT_STREQ(bv6.toString().c_str(), "0000000000000000");
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE);
	EXPECT_STREQ(bv7.toString().c_str(), "0000000000000000");
}


TEST(BITVECTOR_2, INT8) {
	int8_t bits[] = {10, 5, -1, 3};
	BitVector<int8_t> bv1 = BitVector<int8_t>(1, bits);
	EXPECT_STREQ(bv1.toString().c_str(), "0");
	BitVector<int8_t> bv2 = BitVector<int8_t>(2, bits);
	EXPECT_STREQ(bv2.toString().c_str(), "2");
	BitVector<int8_t> bv3 = BitVector<int8_t>(3, bits);
	EXPECT_STREQ(bv3.toString().c_str(), "2");
	BitVector<int8_t> bv4 = BitVector<int8_t>(4, bits);
	EXPECT_STREQ(bv4.toString().c_str(), "a");
	BitVector<int8_t> bv5 = BitVector<int8_t>(5, bits);
	EXPECT_STREQ(bv5.toString().c_str(), "0a");
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(bv6.toString().c_str(), "0a05");
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(bv7.toString().c_str(), "005ff");
	BitVector<int8_t> bv8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 1, bits);
	EXPECT_STREQ(bv8.toString().c_str(), "005ff03");
	BitVector<int8_t> bv9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	EXPECT_STREQ(bv9.toString().c_str(), "205ff03");
	BitVector<int8_t> bv10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits);
	EXPECT_STREQ(bv10.toString().c_str(), "205ff03");
	BitVector<int8_t> bv11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 5, bits);
	EXPECT_STREQ(bv11.toString().c_str(), "0a05ff03");
	BitVector<int8_t> bv12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(bv12.toString().c_str(), "0a05ff03");
	BitVector<int8_t> bv13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(bv13.toString().c_str(), "0a05ff03");
}


TEST(BITVECTOR_2, INT64) {
	int64_t bits[] = {10, 5, -1, 3};
	BitVector<int64_t> bv1 = BitVector<int64_t>(1, bits);
	EXPECT_STREQ(bv1.toString().c_str(), "0");
	BitVector<int64_t> bv2 = BitVector<int64_t>(2, bits);
	EXPECT_STREQ(bv2.toString().c_str(), "2");
	BitVector<int64_t> bv3 = BitVector<int64_t>(3, bits);
	EXPECT_STREQ(bv3.toString().c_str(), "2");
	BitVector<int64_t> bv4 = BitVector<int64_t>(4, bits);
	EXPECT_STREQ(bv4.toString().c_str(), "a");
	BitVector<int64_t> bv5 = BitVector<int64_t>(5, bits);
	EXPECT_STREQ(bv5.toString().c_str(), "0a");
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	EXPECT_STREQ(bv6.toString().c_str(), "000000000000000a0000000000000005");
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	EXPECT_STREQ(bv7.toString().c_str(), "00000000000000005ffffffffffffffff");
	BitVector<int64_t> bv8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 1, bits);
	EXPECT_STREQ(bv8.toString().c_str(), "00000000000000005ffffffffffffffff0000000000000003");
	BitVector<int64_t> bv9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 2, bits);
	EXPECT_STREQ(bv9.toString().c_str(), "20000000000000005ffffffffffffffff0000000000000003");
	BitVector<int64_t> bv10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits);
	EXPECT_STREQ(bv10.toString().c_str(), "20000000000000005ffffffffffffffff0000000000000003");
	BitVector<int64_t> bv11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 5, bits);
	EXPECT_STREQ(bv11.toString().c_str(), "0a0000000000000005ffffffffffffffff0000000000000003");
	BitVector<int64_t> bv12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	EXPECT_STREQ(bv12.toString().c_str(), "000000000000000a0000000000000005ffffffffffffffff0000000000000003");
	BitVector<int64_t> bv13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	EXPECT_STREQ(bv13.toString().c_str(), "000000000000000a0000000000000005ffffffffffffffff0000000000000003");
}


TEST(BITVECTOR_3, INT8) {
	int8_t bits[] = {10, 5, -1, 3};
	BitVector<int8_t> bv1 = BitVector<int8_t>(1, bits);
	BitVector<int8_t> bv1_ = BitVector<int8_t>(bv1);
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int8_t> bv2 = BitVector<int8_t>(2, bits);
	BitVector<int8_t> bv2_ = BitVector<int8_t>(bv2);
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int8_t> bv3 = BitVector<int8_t>(3, bits);
	BitVector<int8_t> bv3_ = BitVector<int8_t>(bv3);
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int8_t> bv4 = BitVector<int8_t>(4, bits);
	BitVector<int8_t> bv4_ = BitVector<int8_t>(bv4);
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int8_t> bv5 = BitVector<int8_t>(5, bits);
	BitVector<int8_t> bv5_ = BitVector<int8_t>(bv5);
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int8_t> bv6_ = BitVector<int8_t>(bv6);
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int8_t> bv7_ = BitVector<int8_t>(bv7);
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int8_t> bv8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int8_t> bv8_ = BitVector<int8_t>(bv8);
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int8_t> bv9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int8_t> bv9_ = BitVector<int8_t>(bv9);
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int8_t> bv10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int8_t> bv10_ = BitVector<int8_t>(bv10);
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int8_t> bv11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int8_t> bv11_ = BitVector<int8_t>(bv11);
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int8_t> bv12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int8_t> bv12_ = BitVector<int8_t>(bv12);
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int8_t> bv13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int8_t> bv13_ = BitVector<int8_t>(bv13);
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(BITVECTOR_3, INT64) {
	int64_t bits[] = {10, 5, -1, 3};
	BitVector<int64_t> bv1 = BitVector<int64_t>(1, bits);
	BitVector<int64_t> bv1_ = BitVector<int64_t>(bv1);
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int64_t> bv2 = BitVector<int64_t>(2, bits);
	BitVector<int64_t> bv2_ = BitVector<int64_t>(bv2);
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int64_t> bv3 = BitVector<int64_t>(3, bits);
	BitVector<int64_t> bv3_ = BitVector<int64_t>(bv3);
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int64_t> bv4 = BitVector<int64_t>(4, bits);
	BitVector<int64_t> bv4_ = BitVector<int64_t>(bv4);
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int64_t> bv5 = BitVector<int64_t>(5, bits);
	BitVector<int64_t> bv5_ = BitVector<int64_t>(bv5);
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int64_t> bv6_ = BitVector<int64_t>(bv6);
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int64_t> bv7_ = BitVector<int64_t>(bv7);
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int64_t> bv8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int64_t> bv8_ = BitVector<int64_t>(bv8);
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int64_t> bv9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int64_t> bv9_ = BitVector<int64_t>(bv9);
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int64_t> bv10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int64_t> bv10_ = BitVector<int64_t>(bv10);
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int64_t> bv11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int64_t> bv11_ = BitVector<int64_t>(bv11);
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int64_t> bv12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int64_t> bv12_ = BitVector<int64_t>(bv12);
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int64_t> bv13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int64_t> bv13_ = BitVector<int64_t>(bv13);
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(BITVECTOR_4, INT8) {
	int8_t bits[] = {10, 5, -1, 3};
	BitVector<int8_t> bv1 = BitVector<int8_t>(1, bits);
	BitVector<int8_t> bv1_ = BitVector<int8_t>(std::move(moveTestConstr(bv1)));
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int8_t> bv2 = BitVector<int8_t>(2, bits);
	BitVector<int8_t> bv2_ = BitVector<int8_t>(std::move(moveTestConstr(bv2)));
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int8_t> bv3 = BitVector<int8_t>(3, bits);
	BitVector<int8_t> bv3_ = BitVector<int8_t>(std::move(moveTestConstr(bv3)));
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int8_t> bv4 = BitVector<int8_t>(4, bits);
	BitVector<int8_t> bv4_ = BitVector<int8_t>(std::move(moveTestConstr(bv4)));
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int8_t> bv5 = BitVector<int8_t>(5, bits);
	BitVector<int8_t> bv5_ = BitVector<int8_t>(std::move(moveTestConstr(bv5)));
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int8_t> bv6_ = BitVector<int8_t>(std::move(moveTestConstr(bv6)));
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int8_t> bv7_ = BitVector<int8_t>(std::move(moveTestConstr(bv7)));
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int8_t> bv8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int8_t> bv8_ = BitVector<int8_t>(std::move(moveTestConstr(bv8)));
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int8_t> bv9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int8_t> bv9_ = BitVector<int8_t>(std::move(moveTestConstr(bv9)));
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int8_t> bv10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int8_t> bv10_ = BitVector<int8_t>(std::move(moveTestConstr(bv10)));
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int8_t> bv11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int8_t> bv11_ = BitVector<int8_t>(std::move(moveTestConstr(bv11)));
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int8_t> bv12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int8_t> bv12_ = BitVector<int8_t>(std::move(moveTestConstr(bv12)));
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int8_t> bv13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int8_t> bv13_ = BitVector<int8_t>(std::move(moveTestConstr(bv13)));
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(BITVECTOR_4, INT64) {
	int64_t bits[] = {10, 5, -1, 3};
	BitVector<int64_t> bv1 = BitVector<int64_t>(1, bits);
	BitVector<int64_t> bv1_ = BitVector<int64_t>(std::move(moveTestConstr(bv1)));
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int64_t> bv2 = BitVector<int64_t>(2, bits);
	BitVector<int64_t> bv2_ = BitVector<int64_t>(std::move(moveTestConstr(bv2)));
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int64_t> bv3 = BitVector<int64_t>(3, bits);
	BitVector<int64_t> bv3_ = BitVector<int64_t>(std::move(moveTestConstr(bv3)));
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int64_t> bv4 = BitVector<int64_t>(4, bits);
	BitVector<int64_t> bv4_ = BitVector<int64_t>(std::move(moveTestConstr(bv4)));
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int64_t> bv5 = BitVector<int64_t>(5, bits);
	BitVector<int64_t> bv5_ = BitVector<int64_t>(std::move(moveTestConstr(bv5)));
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int64_t> bv6_ = BitVector<int64_t>(std::move(moveTestConstr(bv6)));
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int64_t> bv7_ = BitVector<int64_t>(std::move(moveTestConstr(bv7)));
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int64_t> bv8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int64_t> bv8_ = BitVector<int64_t>(std::move(moveTestConstr(bv8)));
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int64_t> bv9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int64_t> bv9_ = BitVector<int64_t>(std::move(moveTestConstr(bv9)));
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int64_t> bv10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int64_t> bv10_ = BitVector<int64_t>(std::move(moveTestConstr(bv10)));
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int64_t> bv11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int64_t> bv11_ = BitVector<int64_t>(std::move(moveTestConstr(bv11)));
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int64_t> bv12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int64_t> bv12_ = BitVector<int64_t>(std::move(moveTestConstr(bv12)));
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int64_t> bv13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int64_t> bv13_ = BitVector<int64_t>(std::move(moveTestConstr(bv13)));
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}
