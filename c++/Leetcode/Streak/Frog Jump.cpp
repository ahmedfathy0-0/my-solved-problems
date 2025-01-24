#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
        {
            return false;
        }
        unordered_map<int, int> stoneIndex;
        for (int i = 0; i < stones.size(); ++i)
        {
            stoneIndex[stones[i]] = i;
        }
        vector<vector<long long>> dp(stones[stones.size() - 1] + 1, vector<long long>(stones[stones.size() - 1] + 1, -1));
        return maxi(stones, dp,stoneIndex ,0, 0);
    }

    bool maxi(vector<int> &stones, vector<vector<long long>> &dp, unordered_map<int, int> &stoneIndex, int index, int k)
    {
        if (index > stones[stones.size() - 1])
        {
            return 0;
        }
        if (index == stones[stones.size() - 1])
        {
            return 1;
        }
        if (dp[index][k] != -1)
        {
            return dp[index][k];
        }
        else
        {

            bool choice1 = false;
            if(stoneIndex.find(index + k) != stoneIndex.end() && k != 0){
                choice1 = maxi(stones, dp, stoneIndex, index + k, k);
            }
            bool choice2 = false;
            if (stoneIndex.find(index + k - 1) != stoneIndex.end() && k - 1 != 0)
            {
                choice2 = maxi(stones, dp, stoneIndex, index + k - 1, k - 1);
            }
            bool choice3 = false;
            if (stoneIndex.find(index + k + 1) != stoneIndex.end())
            {
                choice3 = maxi(stones, dp, stoneIndex, index + k + 1, k + 1);
            }
            if (choice1 || choice2 || choice3)
            {
                dp[index][k] = 1;
                return 1;
            }
            else
            {
                dp[index][k] = 0;
                return 0;
            }
        }
    }
};

int main()
{
    // Input: stones = [0,1,3,5,6,8,12,17]
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    Solution s;
    cout << s.canCross(stones);
    return 0;
}