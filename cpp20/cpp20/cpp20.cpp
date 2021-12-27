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

// 오늘의 주제 : Conditionally Explicit Constructor (조건부 Explicit 생성자)

struct A
{
	A() = default;

	// 명시적으로
	explicit A(int n)
	{
		cout << n << endl;
	}
};

void TestA(A a)
{

}

struct B
{
	// explicit : 원하지 않은 형 변환이 일어나지 않도록 제한!
	template<typename T>
	explicit B(T n)
	{

	}
};

struct C
{
	// 조건부 Explicit
	// - bool에 의한 간접 변환(Implicit Conversion) 은 허용
	// - 그 외에는 explicit
	template<typename T>
	explicit(!std::is_same<T, bool>::value) C(T t)
	{

	}
};


void TestB(B b)
{

}

void TestC(C c)
{

}


int main()
{
	A a;
	TestA(a);



	//TestA(a2); // 엥?

	B b1(2002);
	TestB(b1);
	//TestB(1);
	//TestB(1.f);

	C c1 = true;
	TestC(c1);
	TestC(true);

	// 넌 안됨.
	//TestC(10);
}