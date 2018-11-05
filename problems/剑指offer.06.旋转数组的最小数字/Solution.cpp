#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.empty())
			return 0;
		if (rotateArray.size() == 1)
			return rotateArray[0];

		size_t i = 0;
		size_t j = rotateArray.size() - 1;
		if (rotateArray[i] < rotateArray[j])
			return rotateArray[i];

		while (i + 1 < j)
		{
			size_t k = (i + j) / 2;
			if (rotateArray[i] == rotateArray[k] && rotateArray[k] == rotateArray[j])
				return *min_element(rotateArray.begin() + i, rotateArray.begin() + j + 1);

			if (rotateArray[k] >= rotateArray[i])
				i = k;
			else if (rotateArray[k] <= rotateArray[j])
				j = k;
		}
		return rotateArray[j];
	}
};