#pragma once


#include <cmath>
#include "BitVector.hpp"


using namespace bv;


TEST(LOGLEFTSHIFT_, INT8) {
	EXPECT_EQ(logLeftShift<int8_t>(1, 0), 1);
	EXPECT_EQ(logLeftShift<int8_t>(1, 1), 2);
	EXPECT_EQ(logLeftShift<int8_t>(1, 2), 4);
	EXPECT_EQ(logLeftShift<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE - 2), (int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE - 1), (int8_t) -powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<int8_t>(1, sizeof(int8_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logLeftShift<int8_t>(-1, 0), -1);
	EXPECT_EQ(logLeftShift<int8_t>(-1, 1), -2);
	EXPECT_EQ(logLeftShift<int8_t>(-1, 2), -4);
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 2), (int8_t) -powl(2, sizeof(int8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 1), (int8_t) -powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGLEFTSHIFT_, UINT8) {
	EXPECT_EQ(logLeftShift<uint8_t>(1, 0), 1);
	EXPECT_EQ(logLeftShift<uint8_t>(1, 1), 2);
	EXPECT_EQ(logLeftShift<uint8_t>(1, 2), 4);
	EXPECT_EQ(logLeftShift<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE - 2), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE - 1), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<uint8_t>(1, sizeof(uint8_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, 0),(uint8_t) -1);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, 1),(uint8_t) -2);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, 2),(uint8_t) -4);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE - 2), (uint8_t) (int8_t) -powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE - 1), (uint8_t) (int8_t) -powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<uint8_t>((uint8_t) -1, sizeof(uint8_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGLEFTSHIFT_, INT64) {
	EXPECT_EQ(logLeftShift<int64_t>(1, 0), 1);
	EXPECT_EQ(logLeftShift<int64_t>(1, 1), 2);
	EXPECT_EQ(logLeftShift<int64_t>(1, 2), 4);
	EXPECT_EQ(logLeftShift<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE - 2), (int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE - 1), (int64_t) -powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<int64_t>(1, sizeof(int64_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logLeftShift<int64_t>(-1, 0), -1);
	EXPECT_EQ(logLeftShift<int64_t>(-1, 1), -2);
	EXPECT_EQ(logLeftShift<int64_t>(-1, 2), -4);
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 2), (int64_t) -powl(2, sizeof(int64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 1), (int64_t) -powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGLEFTSHIFT_, UINT64) {
	EXPECT_EQ(logLeftShift<uint64_t>(1, 0), 1);
	EXPECT_EQ(logLeftShift<uint64_t>(1, 1), 2);
	EXPECT_EQ(logLeftShift<uint64_t>(1, 2), 4);
	EXPECT_EQ(logLeftShift<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE - 2), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE - 1), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<uint64_t>(1, sizeof(uint64_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, 0),(uint64_t) -1);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, 1),(uint64_t) -2);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, 2),(uint64_t) -4);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE - 2), (uint64_t) (int64_t) -powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE - 1), (uint64_t) (int64_t) -powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logLeftShift<uint64_t>((uint64_t) -1, sizeof(uint64_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGRIGHTSHIFT_, INT8) {
	EXPECT_EQ(logRightShift<int8_t>((int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), 0), (int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logRightShift<int8_t>((int8_t) (uint8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), 1), (int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logRightShift<int8_t>((int8_t) (uint8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), 2), (int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 3));
	EXPECT_EQ(logRightShift<int8_t>((int8_t) (uint8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), sizeof(int8_t) * BITS_IN_BYTE - 2), 2);
	EXPECT_EQ(logRightShift<int8_t>((int8_t) (uint8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), sizeof(int8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(logRightShift<int8_t>((int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int8_t>((int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), sizeof(int8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<int8_t>((int8_t) powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1), sizeof(int8_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logRightShift<int8_t>(-1, 0), -1);
	EXPECT_EQ(logRightShift<int8_t>(-1, 1), powl(2, sizeof(int8_t) * BITS_IN_BYTE - 1) - 1);
	EXPECT_EQ(logRightShift<int8_t>(-1, 2), powl(2, sizeof(int8_t) * BITS_IN_BYTE - 2) - 1);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 2), (int8_t) 3);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE - 1), (int8_t) 1);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<int8_t>(-1, sizeof(int8_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGRIGHTSHIFT_, UINT8) {
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), 0), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), 1), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), 2), (uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 3));
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), sizeof(uint8_t) * BITS_IN_BYTE - 2), 2);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), sizeof(uint8_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), sizeof(uint8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<uint8_t>((uint8_t) powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1), sizeof(uint8_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logRightShift<uint8_t>(-1, 0), (uint8_t) -1);
	EXPECT_EQ(logRightShift<uint8_t>(-1, 1), powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 1) - 1);
	EXPECT_EQ(logRightShift<uint8_t>(-1, 2), powl(2, sizeof(uint8_t) * BITS_IN_BYTE - 2) - 1);
	EXPECT_EQ(logRightShift<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE - 2), (uint8_t) 3);
	EXPECT_EQ(logRightShift<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE - 1), (uint8_t) 1);
	EXPECT_EQ(logRightShift<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<uint8_t>(-1, sizeof(uint8_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGRIGHTSHIFT_, INT64) {
	EXPECT_EQ(logRightShift<int64_t>((int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), 0), (int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logRightShift<int64_t>((int64_t) (uint64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), 1), (int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logRightShift<int64_t>((int64_t) (uint64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), 2), (int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 3));
	EXPECT_EQ(logRightShift<int64_t>((int64_t) (uint64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), sizeof(int64_t) * BITS_IN_BYTE - 2), 2);
	EXPECT_EQ(logRightShift<int64_t>((int64_t) (uint64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), sizeof(int64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(logRightShift<int64_t>((int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int64_t>((int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), sizeof(int64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<int64_t>((int64_t) powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1), sizeof(int64_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logRightShift<int64_t>(-1, 0), -1);
	EXPECT_EQ(logRightShift<int64_t>(-1, 1), (int64_t) (powl(2, sizeof(int64_t) * BITS_IN_BYTE - 1) - 1));
	EXPECT_EQ(logRightShift<int64_t>(-1, 2), (int64_t) (powl(2, sizeof(int64_t) * BITS_IN_BYTE - 2) - 1));
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 2), (int64_t) 3);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE - 1), (int64_t) 1);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<int64_t>(-1, sizeof(int64_t) * BITS_IN_BYTE * 2), 0);
}


TEST(LOGRIGHTSHIFT_, UINT64) {
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), 0), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1));
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), 1), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 2));
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), 2), (uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 3));
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), sizeof(uint64_t) * BITS_IN_BYTE - 2), 2);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), sizeof(uint64_t) * BITS_IN_BYTE - 1), 1);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), sizeof(uint64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<uint64_t>((uint64_t) powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1), sizeof(uint64_t) * BITS_IN_BYTE * 2), 0);

	EXPECT_EQ(logRightShift<uint64_t>(-1, 0), (uint64_t) -1);
	EXPECT_EQ(logRightShift<uint64_t>(-1, 1), (uint64_t) (powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 1) - 1));
	EXPECT_EQ(logRightShift<uint64_t>(-1, 2), (uint64_t) (powl(2, sizeof(uint64_t) * BITS_IN_BYTE - 2) - 1));
	EXPECT_EQ(logRightShift<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE - 2), (uint64_t) 3);
	EXPECT_EQ(logRightShift<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE - 1), (uint64_t) 1);
	EXPECT_EQ(logRightShift<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE), 0);
	EXPECT_EQ(logRightShift<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE + 1), 0);
	EXPECT_EQ(logRightShift<uint64_t>(-1, sizeof(uint64_t) * BITS_IN_BYTE * 2), 0);
}
