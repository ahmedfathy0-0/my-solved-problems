#include <iostream>

using namespace std;

function createstrings(string s){
    sort(s.begin(), s.end());
    vector<string> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans = createstrings(s);
    cout<<ans.size()<<endl;
    for(string x: ans){
        cout<<x<<endl;
    }
    return 0;
}