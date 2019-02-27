#include <numeric>
#include <vector>

class Solution
{
public:
	int Sum_Solution(int n)
	{
		std::vector<int> v(n);
		std::iota(v.begin(), v.end(), 1);
		return std::accumulate(v.begin(), v.end(), 0);
	}
};
