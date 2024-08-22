#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vector(256,-1);
        int L=0;
        int max=0;
        if(s.size()==0){
            return 0;
        }

        int start =0;
        for (int i=0 ;i< s.size();i++){
            if(vector[s[i]]==-1){
                L++;
                vector[s[i]] = i;
                if(L>max){
                    max=L;
                }
            }
            else {
                if(L>max){
                    max=L;
                }
                vector.clear();
                vector.resize(256, -1);;
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