#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n,1);
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]& dp[j]+1 >dp[i]){
                    dp[i]=dp[j]+1;
                }
                    if(max<dp[i]){
                        max=dp[i];
                    }
            }

        }
        return max;
    }
};
