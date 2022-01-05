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

// 오늘의 주제 : jthread

using namespace std;

mutex mut;

void ThreadMain()
{
	mut.lock();

	while (true)
	{
		// 오래 걸리는 작업
	}

	mut.unlock();
}

void JThreadMain(std::stop_token token)
{
	while (true)
	{
		// 오래 걸리는 작업
		if (token.stop_requested())
			break;
	}

	cout << "끝." << endl;
}

int main()
{
	/*thread t1(ThreadMain);

	t1.join();

	vector<thread> threads;
	for (int i = 0; i < 5; i++)
		threads.push_back(thread(ThreadMain));

	for (int i = 0; i < 5; i++)
		threads[i].join();*/


	// Joining Thread
	jthread jt(JThreadMain);

	// source -> token 추출 -> 새로운 스레드에 전달
	//jt.get_stop_source().get_token();
	//jt.get_stop_token();

	// cooperative interruption
	// 말 그대로 '요청' 한 것. 상대방이 무시하면 뭐...
	//jt.request_stop();



	return 0;
}