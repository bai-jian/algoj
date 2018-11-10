#include <cmath>

class Solution
{
public:
	int Fibonacci(int n)
	{
		if (n <= 1)
			return n;

		int a = 0, b = 1;
		for (int i = 2; i <= n; i++)
		{
			int t = a;
			a = b;
			b += t;
		}
		return b;
	}

	/*
	 * һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
	 * �����������һ��n����̨���ܹ��ж���������
	 */
	int jumpFloor(int number) {
		return Fibonacci(number + 1);
	}

	/*
	 * һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
	 * �����������һ��n����̨���ܹ��ж���������
	 */
	int jumpFloorII(int number) {
		return pow(2, number - 1);
	}

	/*
	 * ���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
	 * ������n��2 * 1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
	 */
	int rectCover(int number) {
		return number == 0 ? 0 : Fibonacci(number + 1);
	}
};