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

// 오늘의 주제 : Attribute

[[nodiscard]]
int Func()
{
	return 10;
}

class Knight
{
public:
	[[nodiscard("생성자 버리지 마세요!")]]
	Knight(int hp) : _hp(hp)
	{

	}

	int _hp = 100;
};

enum class [[nodiscard("ErrorCode 사용하세요")]] ErrorCode
{
	None,
	Warning,
	Critical,
};

ErrorCode GetError()
{
	return ErrorCode::Critical;
}

int Sum(vector<int>& v)
{
	int ret = 0;

	for (int i = 0; i < v.size(); i++)
	{

		// 코드 최적화
		if (v[i] < 0)
		{
			[[likely]]
			ret -= v[i];
		}
		else
		{
			ret += v[i];
		}
	}

	return ret;
}

struct Empty {};

struct NoUniqueAddress
{
	int d;

	[[no_unique_address]]
	Empty e;
};

int main()
{
	// [[notreturn]] C++11
	// [[deprecated]] C++14
	// [[nodiscard]] C++ 17
	// [[nodiscard("사유")]] C++ 20

	// [[likely]] [[unlikely]]
	// [[no_unique_address]]

	int val = Func();

	Knight(100);

	GetError();

	NoUniqueAddress n1, n2, n3;
	cout << &n1.e << endl; 
	cout << &n2.e << endl;;
	cout << &n3.e << endl;
}