#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer(queries.size(), 0);  
        vector<int> prefix(arr.size(), 0);     
        
        prefix[0] = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                answer[i] = prefix[queries[i][1]];
            } else {
                answer[i] = prefix[queries[i][1]] ^ prefix[queries[i][0] - 1];
            }
        } 
        
        return answer;
    }
};


int main (){

    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    Solution s;
    vector<int> res = s.xorQueries(arr,queries);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}