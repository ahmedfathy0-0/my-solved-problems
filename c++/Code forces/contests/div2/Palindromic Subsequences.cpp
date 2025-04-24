#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
         int n;
        cin >> n;
        string s;
        cout << "1 1 ";
        for(int i=2;i<=n-2;i++){
            cout<<i<<" ";
        }
        cout<<1<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}