

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> unused;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        
        for(int i=0; i<n; ++i) unused.push(i);
        
        vector<int> count(n, 0);
        
        for(auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            
            while(!engaged.empty() && engaged.top().first <= start) {
                unused.push(engaged.top().second);
                engaged.pop();
            }
            
            if(!unused.empty()) {
                int room = unused.top();
                unused.pop();
                count[room]++;
                engaged.push({end, room});
            } else {
                auto top = engaged.top();
                engaged.pop();
                int room = top.second;
                long long finish = top.first;
                count[room]++;
                engaged.push({finish + (end - start), room});
            }
        }
        
        int max_count = 0;
        int res = 0;
        for(int i=0; i<n; ++i) {s
            if(count[i] > max_count) {
                max_count = count[i];
                res = i;
            }
        }
        return res;
    }
};