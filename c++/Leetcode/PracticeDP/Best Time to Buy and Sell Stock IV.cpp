#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return maxp(prices, k, 0, true, dp);
    }

    int maxp(vector<int> &prices, int k, int index, bool buy, vector<vector<vector<int>>> &dp)
    {
        if (index >= prices.size() || k == 0)
        {
            return 0;
        }
        if (dp[index][k][buy] != -1)
        {
            return dp[index][k][buy];
        }

        int in1, ex1;
        if (buy)
        {
            in1 = maxp(prices, k, index + 1, false, dp) - prices[index];
            ex1 = maxp(prices, k, index + 1, true, dp);
        }
        else
        {
            in1 = maxp(prices, k - 1, index + 1, true, dp) + prices[index];
            ex1 = maxp(prices, k, index + 1, false, dp);
        }

        dp[index][k][buy] = max(in1, ex1);
        return dp[index][k][buy];
    }
};

int main()
{
    Solution s;
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << s.maxProfit(k, prices) << endl;
    return 0;
}
