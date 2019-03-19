#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return{i, j};
        return{};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> values;
        for (int i = 0; i < nums.size(); i++)
            values.emplace(nums[i], i);
        for (int i = 0; i < nums.size(); i++) {
            auto iter = values.find(target - nums[i]);
            if (iter != values.end() && iter->second != i)
                return{i, iter->second};
        }
        return{};
    }
};
