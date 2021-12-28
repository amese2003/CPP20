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

// 오늘의 주제 : Non-Type Template Parameter

// Non-Type
// - int, enum
// - 포인터, 참조값
// - nullptr_t

// C++20
// - 부동소수점 (floating-point)
// - Literal Type (types of constexpr variables)
// - String Literal

template<double d>
auto GetDouble()
{
	return d;
}

struct ClassType
{
	constexpr ClassType(int) {}
};

template<int N>
struct IntToType
{
	enum { value = N };
};

template<ClassType c>
auto GetClassType()
{
	return c;
}

template<int N>
class StringLiteral
{
public:
	constexpr StringLiteral(char const (&str)[N])
	{
		::copy(str, str + N, _data);
	}

	char _data[N];
};

template<StringLiteral str>
class ClassTemplate {};

template<StringLiteral str>
void FunctionTemplate()
{
	cout << str._data << endl;
}

int main()
{
	auto d1 = GetDouble<5.5>();

	std::array<int, 5> arr;

	auto c1 = GetClassType<ClassType(2021)>();

	ClassTemplate<"Hello World"> cls1;
	FunctionTemplate<"Hello World">();

	// 근데 이딴걸 왜씀?
	// ex) Compile-Time Regular Expression (정규 표현식)
	// std::regex 같은건 런타임 동작.
	// 정규 표현식 패턴을 컴파일타임에 안다면, 굳이 런타임까지 갈 필요 없음

}