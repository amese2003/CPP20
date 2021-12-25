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
// 오늘의 주제 : Designated Initialization (지정 초기화)


struct Pos2D
{
	int x;
	int y;
};

class Pos3D
{
public:
	int x;
	int y;
	int z;
};

int main()
{
	// Aggreate Initialization
	// - 직접 만든 생성자가 없어야 함
	// - 가상 함수 없음
	// - private / protected / non-static 변수
	Pos2D pos{ .y = 2 };
	Pos3D pos{.x = 3, .z = 3};
	Pos3D p1os{ .x = 1, .z = 3.f }; // 축소 변환 (narrowing conversion) 이건 안된다!

}