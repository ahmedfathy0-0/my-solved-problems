#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>  // Include this for stringstream

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        string word;

        // Process both sentences in one pass and update the frequency map
        stringstream iss1(s1);
        stringstream iss2(s2);

        while (iss1 >> word) {
            freq[word]++;
        }
        while (iss2 >> word) {
            freq[word]++;
        }

        // Collect the words that appear only once
        vector<string> ans;
        for (const auto& entry : freq) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};


int main() {
    string s1 = "hello i am ahmed";
    string s2 = "hello i am seif";
    Solution ss;
    cout << ss.uncommonFromSentences(s1, s2).size() << endl;

    return 0;
}
