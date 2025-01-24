#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size(), -1);
        return maxp(prices, 0, 0, true, dp);
    }

    int maxp(vector<int> &prices, int profit, int index, bool buy, vector<int> &dp)
    {
        if (index >= prices.size())
        {
            return profit;
        }

        if (dp[index] != -1 && !buy)
        {
            return dp[index];
        }

        int in1, ex1;
        if (buy)
        {
            in1 = maxp(prices, profit, index + 1, false, dp) - prices[index];
            ex1 = maxp(prices, profit, index + 1, buy, dp);
        }
        else
        {
            in1 = profit + prices[index];
            ex1 = maxp(prices, profit, index + 1, buy, dp);
        }

        if (!buy)
        {
            dp[index] = max(in1, ex1);
        }

        return max(in1, ex1);
    }
};

int main ()
{
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
