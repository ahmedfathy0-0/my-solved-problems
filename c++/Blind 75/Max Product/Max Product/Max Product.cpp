#include <iostream>
using namespace std;
#include <vector>   
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double pre = 1, suf = 1;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (pre == 0) pre = 1;
            if (suf == 0) suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[nums.size() - 1 - i];
            ans = max((double)ans, max(pre, suf));
        }
        return (int)ans;
    }
};



int main()
{
    //test case  [3,-1,4]
	vector<int> nums = { -2,0,-3,9,9,-1,3,2 };
	Solution sol;
	int result = sol.maxProduct(nums);
	cout << result << endl;
}

