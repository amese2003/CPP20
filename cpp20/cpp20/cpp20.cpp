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
// 오늘의 주제 : Three-Way Comparison 연산자 (Spaceship operator <=>)

struct MyInt
{
	MyInt(int value) : _value(value) {}

	// < = > >= == !=
	bool operator<(const MyInt& rhs) const { return _value < rhs._value; };

	::strong_ordering operator<=>(const MyInt& rhs) const = default;

	int _value;
};

struct Strong
{
	std::strong_ordering operator<=> (const Strong&) const = default;
};

struct Weak
{
	std::weak_ordering operator<=> (const Weak&) const = default;
};


struct Partial
{
	std::partial_ordering operator<=> (const Partial&) const = default;
};

struct Test
{
	auto operator<=> (const Test&) const = default;

	Strong s;
	Weak w;
	Partial p;
};


int main()
{
	MyInt a(1);
	MyInt b(2);

	bool test = a < b;
	bool test2 = a > b;
	bool test3 = a <= b;

	// strong ordering
	// weak
	// partial ordering

	// 비교 특성 (Relational, Equivalence, Compareable)
	// - 6종 비교 연산 지원 ==, !=, <, <=, >, >= (Relational))
	// - 모든 Equivalent 한 값들은 서로 구분되지 않고 완전 똑같다. (Equivalence)
	// ex) 대소문자 구별 안하는 문자열 비교 nero Nero
	// - a < b, a == b, a > b 중 하나는 참이다. (Compareable)
	// ex ) float 비교할 때, b가 NaN (not a number)면 3연산이 다 true가 아니다...

	// strong ordering : Relational(o), Equivalence(0), Compareable(0)
	// weak ordering : Relational(o), Compareable(o)
	// partial ordering : Relational(O)

	int a1 = 100;
	int b1 = 200;


	bool a2 = a1 < b1;

	auto ret = a1 <=> b1;

	if (ret < 0)
		cout << "a < b" << endl;
	else if (ret == 0)
		cout << "a == b" << endl;
	else
		cout << "a > b" << endl;


}