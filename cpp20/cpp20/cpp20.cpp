#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template<typename T>
concept integral = std::is_integral_v<T>;

// 오늘의 주제 : concept (컨셉)

//void TestInt(int number)
//{
//    cout << number << endl;
//}
//
//template<typename T>
//void TestTemplate(T number)
//{
//    cout << number << endl;
//}

// 1) Requires Clause(절)
template<typename T>
requires std::integral<T>
void TestConcept1(T number)
{
	cout << number << endl;
}

// 2) Trailing Requires Clause (뒤에 붙는...)
template<typename T>
void TestConcept2(T number) requires std::integral<T>
{
	cout << number << endl;
}

// 3) Constrained Template Parameter (강요된)
template<std::integral T>
void TestConcept3(T number)
{
	cout << number << endl;
}

// 4) Abbreviated Function Template
void TestConcept4(std::integral auto number)
{
	cout << number << endl;
}

class GameObject
{

};

class Knight : public GameObject
{

};

template<typename T>
requires std::derived_from<T, GameObject>
void TestObject(T* obj)
{

}

template<typename T>
concept MyConcept = !std::is_integral_v<T> && std::derived_from<T, GameObject>;

template<typename T>
concept Addable = requires (T a, T b)
{
	a + b;
};

template<typename T>
concept Equality = requires(T a, T b)
{
	{a == b} -> std::convertible_to<bool>;
	{a != b} -> std::convertible_to<bool>;
};

template<typename T>
concept integral = std::is_integral_v<T>;

template<typename T>
concept SignedInt =  std::is_signed_v<T>;


int main()
{
	TestConcept2(10);
	//TestConcept2(1.3f);

	const bool check = _Is_any_of_v<int, short, int, long long>;

	// same_as
	// derived_from

	// integral
	//

	// destructible
	// move_constructible

	// equality_comparable




	/*list<int> li;
	std::sort(li.begin(), li.end());*/

	TestObject(new Knight);
	//TestObject(new int);
}
