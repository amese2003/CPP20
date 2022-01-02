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
#include <numbers>
#include <numeric>
#include <bit>
#include <bitset>
#include <chrono>

// 오늘의 주제 : Calendar


int main()
{
	// C++에 추가된 Time 라이브러리
	// - time point
	// - time duration
	// - clock

	// hh_mm_ss : duration since midnight, split into hours, minutes, seconds, fractional seconds

	// C++ 11 chrono
	// C++ 20 calendar, time_zone

	auto timeOfDay = std::chrono::hh_mm_ss(10.5h + 32min + 1004s + 0.6s);


	cout << timeOfDay << endl;
	cout << timeOfDay.hours() << endl;
	cout << timeOfDay.minutes() << endl;
	cout << timeOfDay.seconds() << endl;
	cout << timeOfDay.subseconds() << endl;
	cout << timeOfDay.to_duration() << endl;


	// Calenar Date
	using namespace chrono;
	chrono::year_month_day ymd1{ year(2022), month(1), day(2) };
	chrono::year_month_day ymd2{ year(2021) / month(11) / day(14) };
	chrono::year_month_day ymd3{ 2021y, November, 14d };


	cout << ymd1 << endl;
	cout << ymd2 << endl;
	cout << ymd3 << endl;


	// year month day
	// day month year
	// month day year
	std::chrono::year_month_day_last ymdl1 = 2021y / November / last;
	std::chrono::year_month_day_last ymdl2 = last / 11 / 2021y;
	std::chrono::year_month_day_last ymdl3 = November / last / 2021;

	auto d1 = ymdl1.day();
	chrono::year_month_day ymd4{ ymdl1 };
	chrono::year_month_weekday ymwkd1{ year(2021) / November / Friday[4] };
	chrono::year_month_day ymd5{ ymwkd1 };

	time_point timePoint = chrono::sys_days(ymd1);

	// Cute Syntax
	// 2021y, 30d, January, February ...., December

	// Validation
	std::chrono::day d{ 31 };
	d++;

	bool valid = d.ok();

	auto leapYear2000{ year(2000) / 2 / 29 };
	auto leapYear2001{ year(2001) / 2 / 29 };
	auto leapYear2002{ year(2002) / 2 / 29 };

	bool valid2 = leapYear2000.ok();
	bool valid3 = leapYear2001.ok();
	bool valid4 = leapYear2002.ok();

	auto now = std::chrono::system_clock::now();
	auto diff = floor<chrono::seconds>(now) - sys_days(1993y / December / 25d);
	cout << diff << endl;
}