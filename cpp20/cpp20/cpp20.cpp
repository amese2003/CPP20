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

// 오늘의 주제 : atomic


int main()
{
	// atomic_ref
	int value = 0;

	//int& ref = value;
	atomic_ref<int> ref(value);

	thread t1([&ref]() {

		for (int i = 0; i < 1000000; i++)
			ref++;
		});

	thread t2([&ref]() {

		for (int i = 0; i < 1000000; i++)
			ref--;
		});

	t1.join();
	t2.join();

	cout << ref << endl;
	// atomic shared_ptr

	// shared_ptr

	// [resource(data)][control block]
	// Thread-Safe?
	// - control block은 thread-safe한게 맞다.


	class User
	{
	public:
		int id = 0;
		int hp = 0;
	};

	shared_ptr<User> targetUser = make_shared<User>();

	targetUser = make_shared<User>();


	targetUser = make_shared<User>();

	// atomic_shared_ptr 과 atomic_weak_ptr이 제안 되었음
	// atomic<shared_ptr<T>>, atomic<weak_ptr<T>>
	atomic<shared_ptr<User>> atomicSharedPtr = make_shared<User>();

	// LockFree 프로그래밍 유용
	// 일상에선 사용할까?
}