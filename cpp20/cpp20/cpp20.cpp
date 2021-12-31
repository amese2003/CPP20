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

// 오늘의 주제 : Container #1

// 1. vector, string 등에 constexpr 사용 가능
// algorithm 100개 이상의 함수들이 constexpr로 바뀜

constexpr int Test()
{
	std::vector<int> v{ 1,4,5,2,3 };
	std::sort(v.begin(), v.end());
	return v.back();
}

// 2. std::array 만드는 방법이 추가됨 (std::to_array)

// 3. std::make_shared로 shared_ptr 생성 가능

template<typename T>
struct ArrayDeleter
{
	void operator()(const T* ptr)
	{
		delete[] ptr;
	}
};

int main()
{
	constexpr int ret = Test();

	enum
	{
		VALUE = ret
	};


	auto arr1 = std::to_array("Hello World");
	for (auto ch : arr1)
		cout << ch;

	cout << endl;

	auto arr2 = std::to_array<int>({1,2,3,4,5});
	for (auto ch : arr2)
		cout << ch;

	cout << endl;


	
	/*int* arr3 = new int[3];
	delete[] arr3;*/
	// C++ 11
	std::shared_ptr<int> sp(new int[10], ArrayDeleter<int>());

	// C++ 20
	std::shared_ptr<double[]> shared_arr = std::make_shared<double[]>(1024);

	shared_arr[1] = 1.0;
}