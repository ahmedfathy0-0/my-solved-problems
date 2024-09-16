#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> minutes;
        for (string time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = min(minDiff, minutes[0] + 24 * 60 - minutes.back());
        return minDiff;
        
    }
};

int main(){

    vector<string> timePoints = {"00:00","23:59","00:00"};
    Solution s;
    cout<<s.findMinDifference(timePoints)<<endl;

    return 0;
}