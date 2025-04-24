#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<string>& adj, int n)
{
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i] = i+1;
    }
    sort(ans.begin(), ans.end(),[&](int a, int b){
       if(a<b){
           return adj[a-1][b-1] =='1';
       }
       else{
           return adj[a-1][b-1] =='0';
       }
    });
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> adj(n);
        for (int i = 0; i < n; i++)
        {
            cin >> adj[i];
        }
        solve(adj, n);
    }
}