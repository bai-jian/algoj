#include <vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		size_t rows = array.size();
		if (rows == 0)
			return false;
		size_t cols = array[0].size();
		if (cols == 0)
			return false;

		int i = 0;
		int j = cols - 1;
		while (i < rows && j >= 0)
		{
			int value = array[i][j];
			if (target == value)
				return true;
			else if (target < value)
				--j;
			else
				++i;
		}
		return false;
	}
};
