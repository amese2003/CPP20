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
#include <set>

// 오늘의 주제 : Container #3
// (contains + prefix/suffix  checking)

int main()
{
	std::set s{ 1,2,3,4,5 };

	auto findIt = s.find(2);
	if (findIt != s.end())
	{
		cout << "잡았다 요놈" << endl;
	}

	if (s.contains(3))
	{
		cout << "잡았다 요놈" << endl;
	}

	std::map<int, int>m{ {1, 100}, {2, 20000} };

	if (m.contains(1))
	{
		cout << "잡았다 요놈" << endl;
	}

	// string의 prefix/suffix (starts_with, ends_with)
	std::string str = "Hello World";

	bool b1 = str.starts_with("Hel");
	bool b2 = str.ends_with("rld");

	cout << b1 << endl;
	cout << b2 << endl;


}