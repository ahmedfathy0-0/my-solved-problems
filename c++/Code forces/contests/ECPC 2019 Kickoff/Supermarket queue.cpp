#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  
  vector<queue<pair<int, int>>> Q(k + 1);  // k queues: each stores {personID, entryTime}
  int mx = -1;                             // max entry time of any "exit event" so far
  vector<int> res;                         // list of sad customers
  
  for (int i = 0, t, x, id; i < 2 * n; ++i) {
    cin >> t;
    if (t == 1) {                          // 1 → entry event
      cin >> id >> x;
      Q[x].emplace(id, i);                 // person enters queue x at event i
    } 
    else {                                 // 2 → exit event
      cin >> x;
      auto [j, d] = Q[x].front();          // j = person ID, d = their entry time
      Q[x].pop();
      
      if (d < mx) {                        // if this person entered BEFORE the last exit event
        res.emplace_back(j);               // => they saw someone enter and exit another queue => sad
      } 
      else { 
        mx = d;                            // update "latest entry time of any exited person"
      }
    }
  }
  
  cout << res.size() << '\n';
  sort(res.begin(), res.end());           // output sorted sad customers
  for (int &x: res) cout << x << ' ';
}
