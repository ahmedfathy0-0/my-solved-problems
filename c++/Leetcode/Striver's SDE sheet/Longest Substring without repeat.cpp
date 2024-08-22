#include <iostream>
#include <vector>
#include <unordered_map>

#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int L=0;
        int max=0;
        if(s.size()==0){
            return 0;
        }
        int start =0;
        for (int i=0 ;i< s.size();i++){
            if(mp.find(s[i])==mp.end()){
                L++;
                mp[s[i]] = i;
                if(L>max){
                    max=L;
                }
            }
            else {
                if(L>max){
                    max=L;
                }
                mp.clear();
                i=start;
                start++;
                L=0;

            }
        }
        return max;
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("dvdf");
    return 0;
}