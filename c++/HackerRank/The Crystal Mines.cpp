#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

vector<int> minjems( vector<int> &cuts, vector<pair<int, int>> &dp, int mine)
{
    for (int i = 1; i <= mine; i++) {
        if(dp[i]!=make_pair(INT_MAX, INT_MAX)) continue;
        dp[i] = {0, i};
        for (int cut : cuts) {
            if (i >= cut) {
                if (dp[i - cut].second  < dp[i].second || (dp[i - cut].second == dp[i].second && dp[i - cut].first < dp[i].first)) {
                    dp[i] = {dp[i - cut].first +1, dp[i - cut].second};
                }
            } else {
                if (i < dp[i].second) {
                    dp[i] = {0, i}; // No cuts, i mines remain
                }
            }
        }
    }
    return {dp[mine].first, dp[mine].second};
}

int main()
{
    int mine;
    cin >> mine;
    vector<int> mines(mine);
    int max = INT_MIN;
    for (int i = 0; i < mine; i++)
    {
        cin >> mines[i];
        if (mines[i] > max)
        {
            max = mines[i];
        }
    }
    int n;
    cin >> n;
    vector<int> cuts(n);
    vector<pair<int, int>> dp(max + 1, {INT_MAX, INT_MAX});
    for (int i = 0; i < n; i++)
    {
        cin >> cuts[i];
    }
    dp[0] = {0, 0};
    for(int i = 0; i < mine; i++)
    {
        vector<int> temp = minjems(cuts, dp, mines[i]);
        cout << temp[1] << " " << temp[0] << endl;

    }



    return 0;
}
