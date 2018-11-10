#include <vector>
using namespace std;

class Solution
{
public:
	void reOrderArray(vector<int> &array)
	{
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array.size() - 1 - i; j++)
			{
				if (!(array[j] & 1) && (array[j + 1] & 1))
				{
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
};