#include "BitVector.hpp"
#include <iostream>


using namespace bv;


int main(int argc, char *argv[]) {
	std::cout << "Hello, World!" << std::endl;
	
	uint8_t tmplt_0[] = {108, 237, 27};  // шаблон для создания бит-вектора
	// tmplt_0 = {01101100, 11101101, 00011011}
	
	BitVector<uint8_t> bv_1{sizeof(uint8_t) * 3 * BITS_IN_BYTE - 4, tmplt_0};  // конструктор
	// bv_1 = 1100.1110.1101.0001.1011 - полученный бит-вектор (точки для удобства)
	// Старшие 4 бита числа 108 были отброшены, ибо не поместились в вектор
	
	std::cout << "1. Разрядность вектора bv_1: " << bv_1.getSize() << std::endl;  // получить разрядность
	// В нашем случае разрядность равна 20
	
	std::cout << "2. Вектор bv_1: " << bv_1.toString() << std::endl;  // получить строку
	// bv_1 = 1100.1110.1101.0001.1011 = ced1b
	
	bv_1.setBit(15, 0);  // установить бит
	// bv_1: 1100.(1)110.1101.0001.1011 -> 1100.(0)110.1101.0001.1011
	
	bv_1.setBit(5, 1);  // установить бит
	// bv_1: 1100.1110.1101.00(0)1.1011 -> 1100.1110.1101.00(1)1.1011
	
	std::cout << "3. Вектор bv_1: " << bv_1.toString() << std::endl;  // получить строку
	// bv_1 = 1100.0110.1101.0011.1011 = c6d3b
	
	std::cout << "4. Бит на позиции 0 bv_1: " << bv_1.getBit(0) << std::endl;  // получить бит
	// bv_1: 1100.1110.1101.0001.101(1) -> 1
	
	std::cout << "5. Бит на позиции 17 bv_1: " << bv_1.getBit(17) << std::endl;  // получить бит
	// bv_1: 11(0)0.1110.1101.0001.1011 -> 0
	
	uint8_t tmplt_1[] = {155, 39};
	// tmplt_1 = {10011011, 00100111}
	
	BitVector<uint8_t> bv_2{sizeof(uint8_t) * 2 * BITS_IN_BYTE - 2, tmplt_1};
	// bv_2 = 01.1011.0010.0111 - полученный бит-вектор (точки для удобства)
	// Старшие 2 бита числа 155 были отброшены, ибо не поместились в вектор
	
	std::cout << "6. Разрядность вектора bv_2: " << bv_2.getSize() << std::endl;  // получить разрядность
	// В нашем случае разрядность равна 14
	
	std::cout << "7. Вектор bv_2: " << bv_2.toString() << std::endl;  // получить строку
	// bv_2 = 01.1011.0010.0111 = 1b27
	
	bv_1.setBits(bv_2, 5);
	// bv_1 = 11000110110100111011
	// bv_2 =  01101100100111      <- смещение 5 бит
	// bv_1 = 10110110010011111011 = 1011.0110.0100.1111.1011
	
	std::cout << "8. Вектор bv_1: " << bv_1.toString() << std::endl;  // получить строку
	// bv_1 = 1011.0110.0100.1111.1011 = b64fb
	
	BitVector<uint8_t> bv_3 = bv_1.getBits(sizeof(uint8_t) * BITS_IN_BYTE + 1, 6);
	// bv_1 = 10110110010011111011
	// bv_3 =      110010011       <- смещение 6 и разрядность 9
	
	std::cout << "9. Разрядность вектора bv_3: " << bv_3.getSize() << std::endl;  // получить разрядность
	// В нашем случае разрядность равна 9
	
	std::cout << "10. Вектор bv_3: " << bv_3.toString() << std::endl;  // получить строку
	// bv_3 = 1.1001.0011 = 193
	
	uint16_t a = bv_1.getFewBits<uint16_t>(sizeof(uint16_t) * BITS_IN_BYTE - 1, 1);
	// bv_1 = 10110110010011111011
	// a =        011001001111101 <- смещение 1 и разрядность 15
	
	std::cout << "11. Переменная a: " << a << std::endl;  // вывод переменной / бит-поля
	// a = 011.0010.0111.1101 = 327c = 12925 (в десятич. записи)
	
	std::cout << "Bye!" << std::endl;
	return 0;
}
