#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include <string>

class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int count=0;
        for(int i=1;i<word.size();i++){
           if(word[i]==word[i-1]){
            if(count<8){
            count++;
            }
            else{
                ans += to_string(count + 1);
                ans+=word[i-1];
                count=0;
            }
           
           }
           else{
            ans += to_string(count + 1);
            ans+=word[i-1];
            count=0;

           }
        }
        ans += to_string(count + 1);
         int size= word.size();
         ans+=word[size-1];
         return ans;
    }
};