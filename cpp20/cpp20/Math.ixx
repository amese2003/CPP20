module; // global  module fragment

// ���� �ܺ� ��� �߰�
#include <vector>

// ��� ����
export module Math;

// import module ....
// math.time�� import���� �ٽ� math ��⿡ �����ؼ� export
// submodule
export import Math.time;

// 1) �Լ� �տ��ٰ� export
export int Add(int a, int b)
{
	return a + b;
}

// 2) export�ϰ� ���� �ֵ��� ���� �����ִ� ���
export
{
	void TestExport()
	{

	}


}

void Internal()
{

}

// 3) namespace ����
export namespace Math
{
	void TestExport2()
	{

	}
}