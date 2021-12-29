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

// 오늘의 주제 : Template Parameter for Lamda

auto sumTyped = [&](int a, int b) {return a + b; };

// 두타입이 달라도 됨.
auto sumGeneric = [](auto a, auto b) {return a + b; }; // C++14 Generic Lambda

// 후자가 전자로 convertible (변환 가능) 해야함.
auto sumDeclType = [](auto a, decltype(a) b) { return a + b; }; // c++ 14 Generic Lambda

// 두 타입이 같아야 함.
auto sumTemplate = []<typename T>(T a, T b) { return a + b; }; // C++ 20 Template Lambda

auto getVectorSize = []<typename T>(const vector<T>& v) {return v.size(); };

int main()
{
	int a = 10;
	int b = 20;

	auto res1 = sumTyped(a, b);

	auto res2 = sumTyped(true, 100); // 101

	auto res3 = sumGeneric(true, 100); // 101

	auto res4 = sumDeclType(true, 100); // 2

	auto res5 = sumTemplate(true, true); // 2

	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
	cout << res4 << endl;
	cout << res5 << endl;

	vector<int> v1{ 1, 2 };
	vector<double> v2{ 1.0, 2.0, 3.0 };

	auto s1 = getVectorSize(v1);
	auto s2 = getVectorSize(v2);

	cout << s1 << endl;
	cout << s2 << endl;
}