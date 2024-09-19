#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        calcways(expression, ans);
        return ans;

        
    }
    void calcways(string expression, vector<int> &ans){
        for(int i = 0; i < expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto l: left){
                    for(auto r: right){
                        if(expression[i] == '+'){
                            ans.push_back(l+r);
                        }
                        else if(expression[i] == '-'){
                            ans.push_back(l-r);
                        }
                        else{
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(ans.size() == 0){
            ans.push_back(stoi(expression));
        }
    }

   

};
int main(){
    Solution s;
    string expression = "2-1-1";
    vector<int> ans = s.diffWaysToCompute(expression);
    for(auto x: ans){
        cout<<x<<",";
    }
    cout<<endl;
    return 0;
}