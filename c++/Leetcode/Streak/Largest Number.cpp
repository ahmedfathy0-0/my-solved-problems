#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }

        sort(array.begin(), array.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        string res ;
        for (const string &num : array) {
            res += num;
        }
        if(res[0]){
            if(res[0]=='0'){
                res='0';
            }
        }
        return res;

    }

};

int main() {
    vector<int> v = {3,30,34,5,9};
    Solution s1;
    s1.largestNumber(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}