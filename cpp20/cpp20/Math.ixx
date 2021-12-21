module; // global  module fragment

// 각종 외부 헤더 추가
#include <vector>

// 모듈 시작
export module Math;

// import module ....
// math.time을 import에서 다시 math 모듈에 포함해서 export
// submodule
export import Math.time;

// 1) 함수 앞에다가 export
export int Add(int a, int b)
{
	return a + b;
}

// 2) export하고 싶은 애들을 따로 묶어주는 방법
export
{
	void TestExport()
	{

	}


}

void Internal()
{

}

// 3) namespace 지정
export namespace Math
{
	void TestExport2()
	{

	}
}