#include <iostream>
using namespace std;
#define ll long long

ll applyOp(ll a, char op, ll b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b; 
}

int main() {
    ll A, B, C;
    char x, y;
    cin >> A >> x >> B >> y >> C;
    if((y=='*' || y=='/') && (x=='+' || x=='-')) {
        ll result = applyOp(B, y, C);
        result = applyOp(A, x, result);
        cout << result << endl;
        return 0;
    }
    ll result = applyOp(A, x, B);
    result = applyOp(result, y, C);

    cout << result << endl;
    return 0;
}
