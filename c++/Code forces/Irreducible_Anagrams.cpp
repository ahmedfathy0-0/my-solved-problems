#include <iostream>
#include <vector>
using namespace std;

void calcPrefix(vector<vector<int>> &count, const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            count[i+1][j] = count[i][j]; 
        }
        count[i+1][s[i] - 'a']++; 
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> count(n + 1, vector<int>(26, 0));
    calcPrefix(count, s);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
             
        int distinct_chars = 0;
        for (int i = 0; i < 26; i++) {
            if (count[r][i] - count[l-1][i]) {
                distinct_chars++;
            }
        }
        
        if(l==r || s[l-1] != s[r-1] || distinct_chars > 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
