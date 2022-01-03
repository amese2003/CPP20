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

// 오늘의 주제 : semaphore

counting_semaphore<1> sem(0);
vector<int> vec;

void PrepareWork()
{
	vec.insert(vec.end(), { 1,2,3,4,5 });

	this_thread::sleep_for(1s);

	cout << "데이터 준비됨." << endl;
	sem.release();
}

void CompleteWork()
{
	cout << "데이터 기다리는중..." << endl;
	sem.acquire();

	cout << "데이터 출력중" << endl;

	for (auto n : vec)
		cout << n << endl;
}

int main()
{
	// mutex
	// 화장실 키
	// [키]

	// semaphore
	// 화장실
	// [키][키][키]

	//counting_semaphore<3>;
	//binary_semaphore = counting_semaphore<1>;

	// max(); // 최대 카운터값
	// acquire(); // counter를 1만큼 감소 (counter = 0 이면 양수 될 때 까지 대기)
	// release(upd = 1); // counter를 upd만큼 증가 (대기하던 스레드가 있으면 풀어줌)
	// try_acquire(); // 카운터가 0보다 크면, 1감소
	// try_acquire_for(relTime); // 최대 relTime만큼 counter를 1 감소하려 시도
	// try_acquire_until(absTime); // 최대 absTime까지 counter를 1 감소하려 시도

	thread t1(PrepareWork);
	thread t2(CompleteWork);

	t1.join();
	t2.join();

	return 0;
}