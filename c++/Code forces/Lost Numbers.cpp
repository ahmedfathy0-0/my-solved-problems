#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// All possible values
vector<int> values = {4, 8, 15, 16, 23, 42};

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main() {
    int res1 = ask(1, 2); 
    int res2 = ask(2, 3);  
    int res3 = ask(3, 4);  
    int res4 = ask(4, 5);  

    do {
        if (
            values[0] * values[1] == res1 &&
            values[1] * values[2] == res2 &&
            values[2] * values[3] == res3 &&
            values[3] * values[4] == res4
        ) {
            cout << "! ";
            for (int x : values)
                cout << x << " ";
            cout << endl;
            cout.flush();
            return 0;
        }
    } while (next_permutation(values.begin(), values.end()));

    return 0; // Failsafe
}
