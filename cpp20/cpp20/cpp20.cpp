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

using namespace std::chrono;
// 오늘의 주제 : Time Zone

int main()
{
	// 온라인 게임 (한국 / 북미 / 유럽)
	// 프랑스 / 독일 / 러시아 / 영국 / .....
	// 와우 - 오전 6시 던전 / 일퀘 리셋
	// DB 시간 저장할 때? 로컬 시간? UTC 시간?

	// UTC (Coordinated Universal Time 협정 세계시) <-> Local Time (실행 환경)
	// - 영국 UTC+0.00 (Greennwich Mean Time, GMT)
	// - 한국 UTC+9.00
	// - 뉴욕 UTC-5.00

	cout << "UTC" << endl;
	auto utcTime = system_clock::now();
	cout << utcTime << endl;

	// C++ 서버 <-> C# 클라
	// UNIX Epoch (유닉스 시간) - 위키피디아
	// 1970년 1월 1일 00:00:00 협정 세계시 (UTC) 부터 경과시간을 초로 환산하여 정수로 나타낸 것이다.

	__int64 hoursSinceUtc = duration_cast<hours>(utcTime.time_since_epoch()).count();
	cout << "Hours : " << hoursSinceUtc << endl;
	__int64 utcEpoch = duration_cast<seconds>(utcTime.time_since_epoch()).count();
	cout << "Epoch : " << utcEpoch << endl;

	cout << "Local" << endl;
	auto localTime = zoned_time(current_zone(), utcTime);
	auto localTime2 = zoned_time("Asia/Shanghai"s, utcTime);
	cout << localTime << endl;
	cout << localTime2 << endl;

	auto offset = localTime.get_info().offset;
	cout << offset << endl;
}