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

// 오늘의 주제 : consteval / constinit

int SqrRunTime(int n)
{
	return n * n;
}

// c++ 11
constexpr int SqrRunOrCompileTime(int n)
{
	return n * n;
}

// c++ 20
consteval int SqrCompileTime(int n)
{
	return n * n;
}

int main()
{
	// 함수 (일반 vs constexpr vs consteval
	{
		// 컴파일 타임 vs 런타임

		// 컴파일 -> 실행파일(exe) -> 런타임

		constexpr int a = 10;

		enum
		{
			//VAL_1 = SqrRunTime(10),
			VAL_2 = SqrRunOrCompileTime(10),
			VAL_3 = SqrCompileTime(10),
		};

		int val1 = SqrRunTime(a);
		constexpr int val2 = SqrRunOrCompileTime(a);
		int val3 = SqrCompileTime(a);

		// consteval 특징
		// - 조건부 jump, loop 가능
		// - 다수의 명령어로 구성 가능
		// - constexpr 함수 호출 가능
		// - static, thread_local 안 됨
		// - try, goto 안 됨
		// - non-consteval 함수 호출 안 됨
		// - non-constexpr 데이터 사용 안 됨
	}

	// 변수 (const vs constexpr vs constinit)
	{
		// const (컴파일타임 / 런타임 + constness 있음)
		// const 변수의 초기화는 런타임까지 지연시킬 수 있다.
		const int constIntVal = SqrRunTime(10);
		//constIntVal++;

		// constexpr (컴파일타임 + constness 있음)
		// constexpr 변수는 반드시 컴파일 타임에 초기화가 되어야한다.
		constexpr int constExprVal = SqrCompileTime(10);

		// constInit 특징 (컴파일타임 + constness 없음 + static/thread_local)
		// - global 변수, static 변수, thread_local 변수를 대상으로 사용
		// -- 프로그램 시작 시 메모리 할당, 프로그램이 끝나면 메모리 해제
		// -- thread_local 변수는 thread에 종속적, 특정 thread가 해당 데이터를 사용할 때 생성됨.

		constinit thread_local int constInitVal = SqrRunOrCompileTime(10);

	}
}