#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findSmallestSubsequence(const string& s) {
    int n = s.size();
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'A') continue;

        int j = i;
        int k = 0;

        while (j < n && k < 26) {
            if (s[j] == alphabet[k]) {
                k++;
            }
            j++;
        }

        if (k == 26) {
            minLen = min(minLen, j - i);
        }
    }

    return minLen;
}

int main() {
    ifstream input("collectingofficer.in");
    
    int t;
    input >> t;

    while (t--) {
        int n;
        string s;
        input >> n >> s;
        cout << findSmallestSubsequence(s) << endl;
    }

    return 0;
}
