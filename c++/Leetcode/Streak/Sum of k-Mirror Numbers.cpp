#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // Convert a number to a string in base-k
    string toBaseK(long long num, int base) {
        string res;
        while (num > 0) {
            res += '0' + (num % base);
            num /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Generate the first `n` k-mirror numbers and return their sum
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // Try increasing lengths of palindromes
        for (int len = 1; count < n; ++len) {
            // Half-length for building palindromes
            int halfLen = (len + 1) / 2;

            // Range of the left half of palindrome
            long long start = pow(10, halfLen - 1);
            long long end = pow(10, halfLen);

            for (long long half = start; half < end && count < n; ++half) {
                string left = to_string(half);
                string right = left;
                reverse(right.begin(), right.end());

                // Generate odd-length palindrome
                string oddPalStr = left + right.substr(1);
                long long oddPal = stoll(oddPalStr);
                if (isPalindrome(toBaseK(oddPal, k))) {
                    sum += oddPal;
                    ++count;
                    if (count == n) break;
                }

                // Generate even-length palindrome
                string evenPalStr = left + right;
                long long evenPal = stoll(evenPalStr);
                if (isPalindrome(toBaseK(evenPal, k))) {
                    sum += evenPal;
                    ++count;
                    if (count == n) break;
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    cout << sol.kMirror(2, 5) << endl;  // Output: 25
    cout << sol.kMirror(3, 7) << endl;  // Output: 499
    cout << sol.kMirror(4, 5) << endl;  // Output: 66
    return 0;
}
