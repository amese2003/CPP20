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

// 오늘의 주제 : Span

void PrintArray(int* arr, int len)
{
	cout << "array size() = " << len << endl;
	for (int i = 0; i < len; i++)
		cout << arr[i] << endl;
}

void Print(std::span<int> container)
{
	cout << "container size() = " << container.size() << endl;
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << endl;
}



int main()
{
	// std::span = C배열, std::array, std:;vector, std::string 등의
	// 연이은 객체 시퀸스 (contiguous sequence of objects)를 참조 (refer)

	// c타입 배열
	int arr[] = { 1,2,3,4,5 };
	const int size = sizeof(arr);
	const int len = sizeof(arr) / sizeof(int);
	PrintArray(arr, len);
	Print(arr);

	// <type T, size_t Extent = dynamic_extent>
	// std::span
	// - static_extent = 컴파일 타임에 크기가 정해짐
	// - dynamic_extent
	// 포인터 + 크기

	vector<int> myVec{ 1,2,3,4,5 };
	vector<int> myVec2{ 6,7,8,9,10 };

	std::span<int> dynamicSpan(myVec);
	std::span<int, 5> staticSpan(myVec2);

	Print(dynamicSpan);
	Print(staticSpan);

	dynamicSpan = staticSpan;
	//staticSpan = dynamicSpan; // Error

	// 포인터/사이즈를 이용해서 span 생성
	std::span<int> span1(myVec.data(), myVec.size());
	Print(span1);

	// 부분적으로 잘라서 만들기
	std::span<int> span2(span1.subspan(1, span1.size() - 3));
	Print(span2);

	//vector<int> vec3(myVec.begin(), myVec.end());

	// 1 ~ 2 범위 대상으로, 4함수 실행하고, 3부터 시작해서 기록
	std::transform(span1.begin(), span1.end(), span1.begin(), [](int i) {return i * i; });
	Print(span1);
	Print(myVec); // 원본 데이터가 수정됨!
}