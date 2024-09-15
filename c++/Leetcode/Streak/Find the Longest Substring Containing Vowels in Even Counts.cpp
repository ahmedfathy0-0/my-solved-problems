#include <iostream>
using namespace std;

#include <vector>
#include <string>

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(1<<5, -1);
        int mask = 0b00000;
        dp[mask] = 0;
        int ans = 0;
        for (int i=0; i<n;i++){
            if(s[i] == 'a'){
                mask ^= 0b10000;
            } else if(s[i] == 'e'){
                mask ^= 0b01000;
            } else if(s[i] == 'i'){
                mask ^= 0b00100;
            } else if(s[i] == 'o'){
                mask ^= 0b00010;
            } else if(s[i] == 'u'){
                mask ^= 0b00001;
            }
            if(dp[mask] == -1){
                dp[mask] = i+1;
            } else {
                ans = max(ans, i-dp[mask]+1);
            }

        }
        return ans;
        
    }
};
int main (){

    string s = "eleetminicoworoep";
    Solution s;
    cout<<s.findTheLongestSubstring(s)<<endl;

    return 0;
}