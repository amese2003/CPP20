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

// 오늘의 주제 : using enum in Local Scopes

enum class Color
{
	Red,
	Black,
	Blue,
};



int main()
{
	Color color = Color::Blue;

	switch (color)
	{
	case Color::Red:
		break;
	case Color::Black:
		break;
	case Color::Blue:
		break;
	default:
		break;
	}

	switch (color)
	{
		using enum Color;
	case Red:
		break;
	case Black:
		break;
	case Blue:
		break;
	default:
		break;
	}

	return 0;
}