#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int x = n&k;


        cout << (n^x) + (k^x) << endl;
    }
}