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
#include <chrono>
#include <format>
#include <source_location>
#include <functional>

// 오늘의 주제 : 기타 함수

void PrintLog(const char* filename, int line)
{
	cout << format("{} Line({})", filename, line) << endl;
}

int Add(int a, int b)
{
	return a + b;
}

void Test()
{
	if (std::is_constant_evaluated())
	{
		// 컴파일
	}
	else
	{
		// 런타임
	}
}

int main()
{
	// 로그 남길 때
	// 멀티스레드 환경에서 데드락 탐지
	// 메모리 누수를 잡기 위해서 할당/해제
	// source_location
	PrintLog(__FILE__, __LINE__);

	auto src = std::source_location::current();
	PrintLog(src.file_name(), src.line());


	// bind_front
	//Add(10, 20);
	using namespace std::placeholders;
	auto func = std::bind(Add, 10, _1);
	cout << func(20) << endl;

	auto func2 = std::bind_front(Add, 10);
	cout << func2(20) << endl;

	auto func3 = [](int b) { return Add(10, b); };
	cout << func3(20) << endl;

	// is_constant_evaluated
	// consteval 붙은 함수는 컴파일 타임에 실행됨
	// constexpr 붙은 함수는 컴파일/런타임 둘다 됨
	// 보통 함수 런타임

	
}