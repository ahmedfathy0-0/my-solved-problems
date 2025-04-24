#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                nums[i] += nums[i - 1];
            }
            if (nums[i] % k == 0) {
                ans++;
            }
            ans += count[(nums[i] % k + k) % k];
            count[(nums[i] % k + k) % k]++;
        }
        return ans;     
    }
};

