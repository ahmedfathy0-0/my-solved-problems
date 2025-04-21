#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> m;
            for(auto i=0;i<answers.size();i++){
                m[answers[i]]++;
            }
            int ans = 0;
            for(auto i:m){
                int x = i.first;
                int y = i.second;
                if(y%(x+1)==0){
                    ans+=y/(x+1)*(x+1);
                }else{
                    ans+=y/(x+1)*(x+1)+(x+1);
                }
            }
            return ans;
            
        }
    };