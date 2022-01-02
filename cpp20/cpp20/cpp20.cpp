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

// 오늘의 주제 : Format

int main()
{
	//printf("%d", 10);

	// format		: 포맷 스트링
	// format_to	: 결과를 output iterator에 반환
	// format_to_n	: 최대 n개 문자를 output iterator에 반환

	int value = 20;
	cout << format("Hello C++{}", value) << endl;

	string buffer;
	format_to(std::back_inserter(buffer), "Hello C++{}", 20);
	cout << buffer << endl;

	buffer.clear();
	format_to_n(std::back_inserter(buffer), 5, "Hello C++{}", 20);
	cout << buffer << endl;

	// 진짜로 { 쓰고싶으면? {{ 두개를 사용하면 됨.
	cout << format("{{Hello C++{}}}", value) << endl;


	cout << format("{} {} {}", 10, 20, 30) << endl;
	cout << format("{0} {2} {1}", 10, 20, 30) << endl;

	// Fill Character (빈칸 채우는 문자 지정 가느으. 기본값은 space)
	// Alignment
	// < left (숫자가 아니라면 얘가 default
	// > right (숫자라면 얘가 default)
	// ^ center

	int num = 100;
	cout << format("{:10}", num) << endl;
	cout << format("{:10}", 'x') << endl;
	cout << format("{:*<10}", 'x') << endl;
	cout << format("{:*>10}", 'x') << endl;
	cout << format("{:*^10}", 'x') << endl;

	// 부호
	// 정수나 부동소수점에 사용
	// + 양수
	// - 음수 << default

	cout << format("{0:}, {0:+}, {0:-}, {0: }", 0) << endl;
	cout << format("{0:}, {0:+}, {0:-}, {0: }", 1) << endl;
	cout << format("{0:}, {0:+}, {0:-}, {0: }", -1) << endl;

	// [#]
	// 정수에 대해, 0b, 0, 0x 이진, 팔진, 십육진
	// 0 : pad with leading zeros

	cout << format("{:#015}", 0x78) << endl;
	cout << format("{:#015b}", 0x78) << endl;
	cout << format("{:015x}", 0x78) << endl;

	// [width / precision]
	// width : {:n} n은 minimum width
	// precision : .에다가 양수 조합 (string이라면 문자 개수, float라면 formatting precision)
	int i = 123456789;
	double d = 123.456789;

	cout << "---" << format("{}", i) << "---" << endl;
	cout << "---" << format("{:15}", i) << "---" << endl; // w = 15
	cout << "---" << format("{}", d) << "---" << endl;
	cout << "---" << format("{:15}", d) << "---" << endl; // w = 15

	cout << "---" << format("{:.100}", d) << "---" << endl; // p = 50
	cout << "---" << format("{:.8}", d) << "---" << endl;
	cout << "---" << format("{:.5}", d) << "---" << endl;
	cout << "---" << format("{:.5}", "Hello World") << "---" << endl;

	// [Type]
	// 대부분 컴파일러가 알아서 어떤 타입인지 추론은 해줌.
	// 근데 우리가 지정할수도 있다.
	// s : string
	// b : binary
	// B : b와 같지만 OB로 시작
	// d : decimal
	// o : octal
	// x : hexadecimal
	// X : x와 같지만  OX로 시작
	// 부동소수점 관련 (e, E, f, F, g, G) : 생략 (지수 표시, 정밀도 등)

	cout << format("{:}", num) << endl;
	cout << format("{:d}", num) << endl;
	cout << format("{:b}", num) << endl;
	cout << format("{:o}", num) << endl;
	cout << format("{:x}", num) << endl;

	// [User Define Types]
	// std::formatter 클래스를 신규 타입에 대해 특수화
	// - 멤버 함수 parse, format을 구현해야함
	// -- 근데 아직 버그가 있다! C2039 에러
}