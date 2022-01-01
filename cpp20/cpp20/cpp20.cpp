#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>
#include <concepts>
#include <coroutine>
#include "MyCoroutine.h"
#include <array>
#include <set>
#include <numbers>
#include <numeric>
#include <bit>
#include <bitset>

// 오늘의 주제 : 비트 연산

unsigned int BitCount(unsigned int flag)
{
	if (flag == 0)
		return 0;

	// 0b1010100
	// 0b101010
	return flag % 2 + BitCount(flag / 2);
}

int main()
{
	// 암호학
	// 게임서버 ID (uint64)
	// 기타 알고리즘 문제

	// 파자집 : 피자 주문하는데, 0 ~ 19번 스무가지의 토핑이 존재
	//bool toppings[20];

	{
		// 전체 구하기
		unsigned int fullPiza = (1 << 20) - 1;

		// 추가
		enum {PEPPERONI = 3};
		unsigned int toppings = 0;
		toppings |= (1 << PEPPERONI);

		bool added = (toppings & (1 << PEPPERONI));

		toppings &= ~(1 << PEPPERONI);

		toppings ^= (1 << PEPPERONI);

		int count = BitCount(toppings);

		// 최소 원소 찾기

		// (끝에 붙에있는 0은 몇개인가?)
		// vs c++ : _BitScanForward(&index, toppings)
		// gcc : __builtin_ctz(toppings);

		int a = 3;
	}

	// 엔디안
	int b = 0x11223344;
	// [44 33 22 11] little
	// [11 22 33 44] big

	// 네트워크, 파일 입출력
	if (std::endian::native == std::endian::big)
	{
		cout << "big" << endl;
	}
	else
	{
		cout << "little" << endl;
	}

	float n1 = 1.0f;
	int n2 = static_cast<int>(n1);

	int n3 = bit_cast<int>(n1);

	// bit_cast : 새로운 캐스팅
	// has_single_bit	: 어떤 숫자가 2^n 형태인지 (2의 거듭제곱)
	// popcount : unsigned int 숫자에서 1의 개수
	// bit_ceil : 해당 값보다 작지 않은 (2의 거듭제곱)중 제일 작은 것 (floor < num < ceil)
	// bit_floor : 해당 값보다 크지 않은 (2의 거듭제곱)중 제일 큰 것 (floor < num < ceil)
	// bit_width : 해당 값을 표현하기 위해 필요한 최소 비트 개수
	// rotl : bitwise left-rotation
	// rotr : bitwise right-rotation
	// countl_zero : 제일 큰 비트부터 시작해서, 연속된 0의 개수
	// countl_one : 제일 큰 비트부터 시작해서, 연속된 1의 개수
	// countr_zero : 제일 작은 비트부터 시작해서, 연속된 0의 개수
	// countr_one : 제일 작은 비트부터 시작해서, 연속된 1의 개수

	std::uint8_t num = 0b00110010;
	cout << boolalpha;

	cout << std::has_single_bit(num) << endl; // false
	cout << popcount(num) << endl; // 3
	cout << std::bitset<8>(std::bit_ceil(num)) << endl; // 0b01000000
	cout << std::bitset<8>(std::bit_floor(num)) << endl; // 
	cout << std::bit_width(5u) << endl; // width(0x000101) = 3
	cout << std::bitset<8>(std::rotl(num, 2)) << endl; // 0b11001000
	cout << std::bitset<8>(std::rotr(num, 2)) << endl; // 0b10001100
	cout << countl_zero(num) << endl; // 2
	cout << countl_one(num) << endl; // 0
	cout << countr_zero(num) << endl; // 1
	cout << countr_one(num) << endl; // 0
}