#pragma once


#include "BitVector.hpp"


using namespace bv;


template <std::integral IntType>
BitVector<IntType> moveTestOp(const BitVector<IntType> &bit_vector) {
	return bit_vector;
}


TEST(OPCOPY, INT8) {
	int8_t bits[] = {10, 5, -1, 3};
	BitVector<int8_t> bv1 = BitVector<int8_t>(1, bits);
	BitVector<int8_t> bv1_{};
	bv1_ = bv1;
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int8_t> bv2 = BitVector<int8_t>(2, bits);
	BitVector<int8_t> bv2_{};
	bv2_ = bv2;
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int8_t> bv3 = BitVector<int8_t>(3, bits);
	BitVector<int8_t> bv3_{};
	bv3_ = bv3;
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int8_t> bv4 = BitVector<int8_t>(4, bits);
	BitVector<int8_t> bv4_{};
	bv4_ = bv4;
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int8_t> bv5 = BitVector<int8_t>(5, bits);
	BitVector<int8_t> bv5_{};
	bv5_ = bv5;
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int8_t> bv6_{};
	bv6_ = bv6;
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int8_t> bv7_{};
	bv7_ = bv7;
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int8_t> bv8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int8_t> bv8_{};
	bv8_ = bv8;
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int8_t> bv9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int8_t> bv9_{};
	bv9_ = bv9;
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int8_t> bv10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int8_t> bv10_{};
	bv10_ = bv10;
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int8_t> bv11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int8_t> bv11_{};
	bv11_ = bv11;
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int8_t> bv12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int8_t> bv12_{};
	bv12_ = bv12;
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int8_t> bv13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int8_t> bv13_{};
	bv13_ = bv13;
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(OPCOPY, INT64) {
	int64_t bits[] = {10, 5, -1, 3};
	BitVector<int64_t> bv1 = BitVector<int64_t>(1, bits);
	BitVector<int64_t> bv1_{};
	bv1_ = bv1;
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int64_t> bv2 = BitVector<int64_t>(2, bits);
	BitVector<int64_t> bv2_{};
	bv2_ = bv2;
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int64_t> bv3 = BitVector<int64_t>(3, bits);
	BitVector<int64_t> bv3_{};
	bv3_ = bv3;
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int64_t> bv4 = BitVector<int64_t>(4, bits);
	BitVector<int64_t> bv4_{};
	bv4_ = bv4;
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int64_t> bv5 = BitVector<int64_t>(5, bits);
	BitVector<int64_t> bv5_{};
	bv5_ = bv5;
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int64_t> bv6_{};
	bv6_ = bv6;
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int64_t> bv7_{};
	bv7_ = bv7;
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int64_t> bv8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int64_t> bv8_{};
	bv8_ = bv8;
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int64_t> bv9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int64_t> bv9_{};
	bv9_ = bv9;
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int64_t> bv10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int64_t> bv10_{};
	bv10_ = bv10;
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int64_t> bv11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int64_t> bv11_{};
	bv11_ = bv11;
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int64_t> bv12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int64_t> bv12_{};
	bv12_ = bv12;
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int64_t> bv13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int64_t> bv13_{};
	bv13_ = bv13;
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(OPMOVE, INT8) {
	int8_t bits[] = {10, 5, -1, 3};
	BitVector<int8_t> bv1 = BitVector<int8_t>(1, bits);
	BitVector<int8_t> bv1_{};
	bv1_ = std::move(moveTestOp(bv1));
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int8_t> bv2 = BitVector<int8_t>(2, bits);
	BitVector<int8_t> bv2_{};
	bv2_ = std::move(moveTestOp(bv2));
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int8_t> bv3 = BitVector<int8_t>(3, bits);
	BitVector<int8_t> bv3_{};
	bv3_ = std::move(moveTestOp(bv3));
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int8_t> bv4 = BitVector<int8_t>(4, bits);
	BitVector<int8_t> bv4_{};
	bv4_ = std::move(moveTestOp(bv4));
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int8_t> bv5 = BitVector<int8_t>(5, bits);
	BitVector<int8_t> bv5_{};
	bv5_ = std::move(moveTestOp(bv5));
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int8_t> bv6 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int8_t> bv6_{};
	bv6_ = std::move(moveTestOp(bv6));
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int8_t> bv7 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int8_t> bv7_{};
	bv7_ = std::move(moveTestOp(bv7));
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int8_t> bv8 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int8_t> bv8_{};
	bv8_ = std::move(moveTestOp(bv8));
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int8_t> bv9 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int8_t> bv9_{};
	bv9_ = std::move(moveTestOp(bv9));
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int8_t> bv10 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int8_t> bv10_{};
	bv10_ = std::move(moveTestOp(bv10));
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int8_t> bv11 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int8_t> bv11_{};
	bv11_ = std::move(moveTestOp(bv11));
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int8_t> bv12 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int8_t> bv12_{};
	bv12_ = std::move(moveTestOp(bv12));
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int8_t> bv13 = BitVector<int8_t>(sizeof(int8_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int8_t> bv13_{};
	bv13_ = std::move(moveTestOp(bv13));
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}


TEST(OPMOVE, INT64) {
	int64_t bits[] = {10, 5, -1, 3};
	BitVector<int64_t> bv1 = BitVector<int64_t>(1, bits);
	BitVector<int64_t> bv1_{};
	bv1_ = std::move(moveTestOp(bv1));
	EXPECT_STREQ(bv1.toString().c_str(), bv1_.toString().c_str());
	BitVector<int64_t> bv2 = BitVector<int64_t>(2, bits);
	BitVector<int64_t> bv2_{};
	bv2_ = std::move(moveTestOp(bv2));
	EXPECT_STREQ(bv2.toString().c_str(), bv2_.toString().c_str());
	BitVector<int64_t> bv3 = BitVector<int64_t>(3, bits);
	BitVector<int64_t> bv3_{};
	bv3_ = std::move(moveTestOp(bv3));
	EXPECT_STREQ(bv3.toString().c_str(), bv3_.toString().c_str());
	BitVector<int64_t> bv4 = BitVector<int64_t>(4, bits);
	BitVector<int64_t> bv4_{};
	bv4_ = std::move(moveTestOp(bv4));
	EXPECT_STREQ(bv4.toString().c_str(), bv4_.toString().c_str());
	BitVector<int64_t> bv5 = BitVector<int64_t>(5, bits);
	BitVector<int64_t> bv5_{};
	bv5_ = std::move(moveTestOp(bv5));
	EXPECT_STREQ(bv5.toString().c_str(), bv5_.toString().c_str());
	BitVector<int64_t> bv6 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2, bits);
	BitVector<int64_t> bv6_{};
	bv6_ = std::move(moveTestOp(bv6));
	EXPECT_STREQ(bv6.toString().c_str(), bv6_.toString().c_str());
	BitVector<int64_t> bv7 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 2 + 1, bits);
	BitVector<int64_t> bv7_{};
	bv7_ = std::move(moveTestOp(bv7));
	EXPECT_STREQ(bv7.toString().c_str(), bv7_.toString().c_str());
	BitVector<int64_t> bv8 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 1, bits);
	BitVector<int64_t> bv8_{};
	bv8_ = std::move(moveTestOp(bv8));
	EXPECT_STREQ(bv8.toString().c_str(), bv8_.toString().c_str());
	BitVector<int64_t> bv9 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 2, bits);
	BitVector<int64_t> bv9_{};
	bv9_ = std::move(moveTestOp(bv9));
	EXPECT_STREQ(bv9.toString().c_str(), bv9_.toString().c_str());
	BitVector<int64_t> bv10 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 3, bits);
	BitVector<int64_t> bv10_{};
	bv10_ = std::move(moveTestOp(bv10));
	EXPECT_STREQ(bv10.toString().c_str(), bv10_.toString().c_str());
	BitVector<int64_t> bv11 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 3 + 5, bits);
	BitVector<int64_t> bv11_{};
	bv11_ = std::move(moveTestOp(bv11));
	EXPECT_STREQ(bv11.toString().c_str(), bv11_.toString().c_str());
	BitVector<int64_t> bv12 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4 - 1, bits);
	BitVector<int64_t> bv12_{};
	bv12_ = std::move(moveTestOp(bv12));
	EXPECT_STREQ(bv12.toString().c_str(), bv12_.toString().c_str());
	BitVector<int64_t> bv13 = BitVector<int64_t>(sizeof(int64_t) * BITS_IN_BYTE * 4, bits);
	BitVector<int64_t> bv13_{};
	bv13_ = std::move(moveTestOp(bv13));
	EXPECT_STREQ(bv13.toString().c_str(), bv13_.toString().c_str());
}
