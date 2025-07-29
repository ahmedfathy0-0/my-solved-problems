#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

typedef long double ld;

ld safe_sqrt(ld x) {
    return sqrtl(max((ld)0.0, x));
}

bool valid(ld a, ld b, ld c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

ld get_area(ld a, ld b, ld c) {
    if (!valid(a, b, c)) return 0;
    ld s = (a + b + c) / 2.0;
    return safe_sqrt(s * (s - a) * (s - b) * (s - c));
}

ld best_area(ld a, ld b, ld c, ld k) {
    ld target = (a + b + c) / 3;
    ld x = target - c;
    if (x < 0) x = 0;
    if (x > k) x = k;
    return get_area(a, b, c + x);
}

int main() {
    ifstream input("sticks.in");
    int T;
    input >> T;
    cout << fixed << setprecision(10);
    
    while (T--) {
        ld a, b, c, k;
        input >> a >> b >> c >> k;

        ld ans = 0;
        ans = max(ans, best_area(b, c, a, k)); 
        ans = max(ans, best_area(c, a, b, k)); 
        ans = max(ans, best_area(a, b, c, k)); 

        cout << ans << '\n';
    }

    return 0;
}
