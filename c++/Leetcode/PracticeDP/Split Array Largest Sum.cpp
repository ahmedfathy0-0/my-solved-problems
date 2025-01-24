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
        int minLargestSum = INT_MAX;
        for (int i = start; i < end; i++) {
            sum += nums[i]; 
            int sum2 = minlargesub(nums, k - 1, i + 1, end, dp);
            if (sum2 != INT_MAX) {
                minLargestSum = min(minLargestSum, max(sum, sum2));
            }
        }
        dp[start][k] = minLargestSum;
        return dp[start][k];
    }
};


class Solution {
    bool good(int x, vector<int> &nums, int k) {
        int cnt = 1, s = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > x) return false;
            s += nums[i];
            if(s > x) { 
                cnt++;
                s = nums[i];
                if(cnt > k) return false;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int s = 0, e = 1e9, ans = INT_MAX;
        // for(int i : nums) e += i;
        
        while(s <= e) {
            int m = (s + e) / 2;
            if(good(m, nums, k)) e = m - 1, ans = min(ans, m);
            else s = m + 1;
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout << s.splitArray(nums, k) << endl;
    return 0;
}