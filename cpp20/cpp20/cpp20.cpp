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
#include <format>
#include <source_location>
#include <functional>
#include <atomic>
#include <thread>
#include <semaphore>
#include <latch>
#include <barrier>
#include <mutex>
#include <syncstream>

// 오늘의 주제 : synchronized output

using namespace std;

void ThreadMain(int threadId)
{
	while (true)
	{
		// accumulate output in an internal buffer and write their content in an atomic step
		std::osyncstream syncStream(std::cout);
		syncStream << format("안녕 나는 스레드 {}", threadId) << endl;
		this_thread::sleep_for(1s);
	}

}

int main()
{
	vector<jthread> threads;

	for (int i = 0; i < 3; i++)
	{
		threads.push_back(jthread(ThreadMain, i));
	}


	return 0;
}