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
// (erase, erase_if)

int main()
{
	vector<int> vec{ -1,2,-3,4,-5 };

	/*for (auto it = vec.begin(); it != vec.end();)
	{
		int value = *it;
		if (value < 0)
		{
			it = vec.erase(it);
		}
		else
		{
			it++;
		}
	}*/

	// 슈퍼 함정 카드
	// -1 2 -3 4 -5
	//  2 4 -3 4 -5
	/*auto newEnd = std::remove_if(vec.begin(), vec.end(), [](int num) {return num < 0; });
	vec.erase(newEnd, vec.end());*/

	// C++20 erase, erase_if
	//std::erase(vec, 2);
	std::erase_if(vec, [](int num) {return num < 0; });

	// C++의 엄청난 함정
	for (auto num : vec)
		cout << num << endl;

}