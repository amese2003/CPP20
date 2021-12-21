#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

import Math;
//import Math.time;
// 오늘의 주제 : module
import MathPartition;


int main()
{
	// 전처리
	// - #include #define
	// 컴파일
	// - 오브젝트 파일 .obj
	// 링크

	// 기존 사용하던 방법의 문제점
	// 1) 빌드속도 (반복된 substitution)
	// 너무너무 느리다
	// 2) 매크로 (#define)
	// 3) 심볼 중복 정의

	// Module
	// - 모듈은 딱 한번만 import 된다
	// - import 순서에 상관 없음
	// - 심볼 중복 정의
	// - 모듈의 이름도 지정 가능
	// - 인터페이스 / 구현부 분리 관리 필요없음
	int sum = Add(1,2);

	//MathTimeFunc();

}
