#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


    class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int mini = INT_MAX;
            int minindex = 0;
    
            for (int i = 0; i < differences.size(); i++) {
                if (differences[i] < mini) {
                    mini = differences[i];
                    minindex = i;
                }
            }
    
            vector<long long> result(differences.size() + 1);
            result[minindex + 1] = 0;
    
            long long maxVal = 0;
            long long minVal = 0;
    
            for (int i = minindex + 2; i < result.size(); i++) {
                result[i] = result[i - 1] + differences[i - 1];
                maxVal = max(maxVal, result[i]);
                minVal = min(minVal, result[i]);
            }
    
            for (int i = minindex; i >= 0; i--) {
                result[i] = result[i + 1] - differences[i];
                maxVal = max(maxVal, result[i]);
                minVal = min(minVal, result[i]);
            }


            long long shift_min = lower - minVal;
            long long shift_max = upper - maxVal;
    
            if (shift_min > shift_max) return 0;
            return shift_max - shift_min + 1;
        }
    };
    