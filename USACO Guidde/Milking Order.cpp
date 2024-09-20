#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> order(m);
    for (int i = 0; i < m; i++) {
        cin>>order[i];
    }
    vector<int> ans(n,0);
    int a,b;
    for (int i = 0; i < k; i++) {
        cin>>a>>b;
        ans[b-1] =a;
    }
    auto previousend = ans.rbegin();
    for (int j = order.size() - 1; j >= 0; j--) {
        auto it = std::find(ans.begin(), ans.end(), order[j]);
        if (j > 0) {
            auto it2 = std::find(ans.begin(), ans.end(), order[j - 1]);
            if (it == ans.end()) {
                if (it2 == ans.end()) {
                    *std::find(previousend, ans.rend(), 0) = order[j];
                } else {
                    auto rit2 = std::reverse_iterator(it2);
                    auto end_pos = std::find(previousend, rit2, 0);
                    previousend = rit2;
                    if (end_pos != ans.rend()) {
                        *end_pos = order[j];
                    }
                }
            }
        } else {
            // When j == 0, we only need to check if order[j] is in ans and place it
            if (it == ans.end()) {
                *std::find(previousend, ans.rend(), 0) = order[j];
            }
        }
    }


    cout<<distance(ans.begin(),find(ans.begin(), ans.end(), 0))+1;

    return 0;




}