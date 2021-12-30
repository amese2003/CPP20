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

// 오늘의 주제 : Range-Based For Loop With Initializer

struct User
{
	int id;
};

User* GetUser()
{


	return nullptr;
}

int main()
{
	// C++ 17
	// if w/ Initializer
	if (int a = 10; a == 10)
	{
		cout << a << endl;
	}

	/*User* user = GetUser();
	if (user == nullptr || user->id == 0)
		return;

	User* user2 = nullptr;

	if (User* user = GetUser(); user == nullptr || user->id == 0)
		return;*/

	// Switch w/ Initializer
	switch (int b = 3; b)
	{
	case 2:
		break;
	case 3:
		cout << "이게 됨?" << endl;
		break;
	}

	// Range-Based for
	for (vector<int> vec{ 1,2,3 }; auto v : vec)
	{
		cout << v << endl;
	}


	return 0;
}