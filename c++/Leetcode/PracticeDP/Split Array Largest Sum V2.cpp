#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() + 10, vector<int>(k + 10, -1));
        return minlargesub(nums, k, 0, nums.size(), dp);
    }

    int minlargesub(vector<int>& nums, int k, int start, int end, vector<vector<int>>& dp) {
        if (k == 0) {
            return (start == end) ? 0 : INT_MAX;
        }
        if (start == end) {
            return (k == 0) ? 0 : INT_MAX;
        }
        if (dp[start][k] != -1) {
            return dp[start][k];
        }
        int sum = 0;
        int minLargestSum = INT_MIN;
        int minSplit = INT_MAX;
        for (int i = start; i < end; i++) {
            if(nums[i] < minSplit) {
                minSplit = nums[i];
            }
            int sum2 = minlargesub(nums, k - 1, i + 1, end, dp);
            if (sum2 != INT_MAX) {
                minLargestSum = max(minLargestSum, minSplit+sum2);
            }
        }
        dp[start][k] = minLargestSum;
        return dp[start][k];
    }
};



int main() {
    Solution s;
    vector<int> nums = {6, 5, 3, 8, 9, 10, 4, 7, 10};
    int k = 4;
    cout << s.splitArray(nums, k) << endl;
    return 0;
}