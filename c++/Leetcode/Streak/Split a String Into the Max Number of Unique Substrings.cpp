#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;


class Solution {
public:
    int maxUniqueSplit(string s) {  
        set<string> unique;

        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(unique.find(temp)==unique.end()){
                    unique.insert(temp);
                    break;
                }
                if(j==s.size()-1){
                    return unique.size()+1;}
            }
        }
        return unique.size();
        
        
    }
};
int main(){
    Solution s;
    cout<<s.maxUniqueSplit("ababccc");
    return 0;
}