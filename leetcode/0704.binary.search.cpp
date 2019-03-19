#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            int value = nums[middle];
            if (target == value)
                return middle;
            else if (target < value)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
};
