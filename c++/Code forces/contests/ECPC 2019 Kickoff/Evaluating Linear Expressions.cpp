#include <iostream>
using namespace std;

int main() {
    int a,b,k;
    cin >> a >> b >> k;
    for(int i = 1; i <= k; i++) {
        cout << a*i +b<< " ";
    }
    cout << endl;
    
    return 0;
}