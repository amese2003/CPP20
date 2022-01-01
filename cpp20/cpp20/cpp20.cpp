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

// 오늘의 주제 : Arithmetic (산술)

int main()
{
	int x = -2;
	unsigned int y = 10;

	unsigned int tempX = (unsigned int)x;
	auto z = (tempX < y);

	cout << std::boolalpha;
	cout << "-2 < 7 = " << (x < y) << endl;
	cout << "-2 <= 7 = " << (x <= y) << endl;
	cout << "-2 > 7 = " << (x > y) << endl;
	cout << "-2 >= 7 = " << (x >= y) << endl;

	// c++ 20에서 cmp_XX가 추가됨.
	cout << "-2 < 7 = " << std::cmp_less(x, y) << endl;
	cout << "-2 <= 7 = " << std::cmp_less_equal(x, y) << endl;
	cout << "-2 > 7 = " << std::cmp_greater(x, y) << endl;
	cout << "-2 >= 7 = " << std::cmp_greater_equal(x, y) << endl;


	// non-integer 정수가 아닌 애들을 넣으면?
	// std::cmp_less(3, 1.4f) // error


	// 수학 상수 기호들이 추가됨.
	const float Pi = 3.14f;
	std::numbers::pi;
	std::numbers::pi_v<float>;
	std::numbers::sqrt2;
	std::numbers::e;

	// 중간값
	// (a + (b-a) / 2)
	constexpr int mid =	std::midpoint(10, 20);

	// 선형 보간
	// [A  | B]
	// (a + t * (b-a))
	constexpr int ler = std::lerp(10, 20, 0.5);

}