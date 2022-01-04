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

// 오늘의 주제 : latch / barrier

using namespace std;

std::latch workDone(5);
std::mutex coutMutex;


void Print(string msg)
{
	coutMutex.lock();
	cout << msg << endl;
	coutMutex.unlock();
}

void DoWork(string name)
{
	Print(name);
	// TODO
	workDone.arrive_and_wait(); // decrement + blocking
}

void TestLatch()
{
	vector<thread> threads;
	for (int i = 0; i < 5; i++)
		threads.push_back(thread(DoWork, format("{}", i)));

	for (int i = 0; i < 5; i++)
		threads[i].join();

	cout << "잡 완료" << endl;
}

std::barrier workDone2(5);

void DoFullTimeJob()
{
	workDone2.arrive_and_wait(); // 카운트 1 줄이고, 0 될때까지 대기.

	Print("Morning Job Done");


	// -- 재사용
	// [3]

	workDone2.arrive_and_wait();
	Print("Afternoon Job Done");
}

void DoPartTimeJob()
{
	workDone2.arrive_and_drop(); // 카운트 1 줄이고, 0 될떄까지 대기. 그리고 카운트 초기값 1 감소
	Print("Morning Job Done");
}

void TestBarrier()
{
	vector<thread> threads;

	for (int i = 0; i < 3; i++)
		threads.push_back(thread(DoFullTimeJob));

	for (int i = 0; i < 2; i++)
		threads.push_back(thread(DoPartTimeJob));

	for (thread& t : threads)
		t.join();
}

int main()
{
	// Producer - Consumer

	// latch : 1회용
	// barrier : 재사용

	// future, condition_variable 등으로 할 수 있는데 굳이?
	// 새로운 기능이 있는건 아닌데 사용법이 간단하고 가장 속도가 빠름.
	//TestLatch();
	//

	TestBarrier();

	return 0;
}