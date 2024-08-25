#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){

    int n;
    cin>>n;
    int count = 0;
    for (int c = 1; c <= n; ++c) {
        for (int b = 1; b <= c; ++b) {
            int a_squared = c * c - b * b;
            int a = (int)sqrt(a_squared);
            if (a * a == a_squared && 1 <= a && a <= b) {
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}