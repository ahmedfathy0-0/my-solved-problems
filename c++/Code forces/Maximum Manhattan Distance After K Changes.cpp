#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maxDistance(string s, int k) {
            int latitude = 0, longitude = 0, ans = 0;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                switch (s[i]) {
                    case 'N':
                        latitude++;
                        break;
                    case 'S':
                        latitude--;
                        break;
                    case 'E':
                        longitude++;
                        break;
                    case 'W':
                        longitude--;
                        break;
                }
                ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
            }
            return ans;
        }
    };

int main() {
    Solution solution;
    string s;
    int k;
    cin >> s >> k;
    cout << solution.maxDistance(s, k) << endl;
    return 0;
}