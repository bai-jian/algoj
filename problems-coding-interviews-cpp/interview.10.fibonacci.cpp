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
	 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
	 * 求该青蛙跳上一个n级的台阶总共有多少种跳法
	 */
	int jumpFloor(int number) {
		return Fibonacci(number + 1);
	}

	/*
	 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
	 * 求该青蛙跳上一个n级的台阶总共有多少种跳法
	 */
	int jumpFloorII(int number) {
		return pow(2, number - 1);
	}

	/*
	 * 我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。
	 * 请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
	 */
	int rectCover(int number) {
		return number == 0 ? 0 : Fibonacci(number + 1);
	}
};