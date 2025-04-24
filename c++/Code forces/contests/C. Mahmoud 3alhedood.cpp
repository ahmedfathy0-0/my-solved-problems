#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long mod_pow(long long b,long long n)
{
    b%=MOD;
    long long s=1;
    while(n)
    {
        if(n%2==1)s=s*b%MOD;
        b=b*b%MOD;
        n/=2;
    }
    return s;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long exponent = (n - 1) * (m - 1) + 1;
    cout << mod_pow(2, exponent) << endl;
    return 0;
}