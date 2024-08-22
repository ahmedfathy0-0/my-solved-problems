#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max;
        if (nums.size() != 0) {
            max = nums[0];
        }
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
			if (sum < 0) {
				sum = 0;
			}
			
        }
        return max;
    }
};

int main() {
	// Test case 1 [-2,1,-3,4,-1,2,1,-5,4]

	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);

	Solution sol;
	cout << sol.maxSubArray(nums) << endl;

	return 0;
}