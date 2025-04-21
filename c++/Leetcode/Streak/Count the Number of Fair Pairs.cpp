#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int min_val = lower - nums[i];
            int max_val = upper - nums[i];

            int left = upper_bound(nums.begin() + i + 1, nums.end(), max_val) - nums.begin();
            int right = lower_bound(nums.begin() + i + 1, nums.end(), min_val) - nums.begin();

            result += (left - right);
        }

        return result;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1, 3, 2, 8};
    int lower = 1, upper = 3;

    cout << s1.countFairPairs(nums, lower, upper) << endl;
    return 0;
}
