#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void checkfound(unordered_set<int>& s, int X, int Y, bool& found1, bool& found2){
    for(auto i : s){
        if(s.find(X+i) != s.end()){
            found1 = true;
        }
        if(s.find(Y+i) != s.end()){
            found2 = true;
        }
        if(found1 && found2){
            return;
        }
    }
}


int main(){
    int N,L,X,Y;
    cin >> N >> L >> X >> Y;
    unordered_set<int> s;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        s.insert(x);
        v[i] = x;
    }
    bool found1 = false;
    bool found2 = false;
    checkfound(s,X,Y,found1,found2);
    if(found1 && found2){
        cout << 0;
    }
    if((found1&& !found2) || (!found1 && found2)){
        cout << 1;
    }
    if(!found1 && !found2){
        for(int i=0;i<N;i++){
            if(v[i]+X <= L){
                s.insert(v[i] + X);
                found1 = false;
                found2 = false;
                checkfound(s, X, Y, found1, found2);
                if (found1 && found2) {
                    cout << 1;
                    return 0;
                }
                s.erase(v[i] + X);
            }
            if(v[i]-X >= 0){
            s.insert(v[i]-X);
            found1 = false;
            found2 = false;
            checkfound(s,X,Y,found1,found2);
            if(found1 && found2){
                cout << 1;
                return 0;
            }
            s.erase(v[i]-X);
            }
        }

        cout << 2;
    }
    return 0;

}