#include <iostream>
#include <vector>
using namespace std;
#define long long ll

int main() {
    int n ,f;
    cin >> n >> f;
    int a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if(b > a) {
            swap(a, b);
        }
        if(f>=a){
            f += a;
        }
        else if(f>=b){
            f += b;
        }
        else{
            cout << "N" << endl;
            return 0;
        }

    }
    cout << "S" << endl;
    return 0;
}