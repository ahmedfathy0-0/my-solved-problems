#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int SubTeams(int n,int k,vector<vector<int>> & dp){
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    if(n==k||k==1){
        return 1;
    }
    int ans =0;
    for(int i =1;i<= n / k;i++){
        ans+= dp[i]+ SubTeams(n-i,k-i,dp);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> dp(n+10,vector<int>(n+10,-1));
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++){
            dp[i][j]+= SubTeams(i,j,dp);
        }
    }
    cout<<dp[n];
    return 0;
}
