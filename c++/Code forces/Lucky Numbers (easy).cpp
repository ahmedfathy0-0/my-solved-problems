#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<long long> superLucky;

void generate(int len) {
    int half = len / 2;
    for (int mask = 0; mask < (1 << len); ++mask) {
        int ones = __builtin_popcount(mask);
        if (ones != half) continue; 

        string s;
        for (int i = len - 1; i >= 0; --i) {
            if (mask & (1 << i)) s += '7';
            else s += '4';
        }

        superLucky.push_back(stoll(s));
    }
}

int main() {
    long long n;
    cin >> n;

    for (int len = 2; len <= 10; len += 2) {
        generate(len);
    }

    sort(superLucky.begin(), superLucky.end());
    
    auto it = lower_bound(superLucky.begin(), superLucky.end(), n);
    
    if (it != superLucky.end()) {
        cout << *it << endl;
    } else {
        cout << "No super lucky number found" << endl;
    }

    return 0;
}
