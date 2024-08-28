#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check (long long mid, long long nb, long long ns, long long nc, long long kb, long long ks, long long kc, long long pb, long long ps, long long pc, long long r){
    long long neededmoney = 0;
    long long required = 0;

    required =  mid * nb;
    if (required > kb){
        neededmoney += (required - kb) * pb;

    }
    if(neededmoney > r){
        return false;
    }
    required = mid * ns;
    if (required > ks){
        neededmoney += (required - ks) * ps;
    }
    if(neededmoney > r){
        return false;
    }
    required = mid * nc;
    if (required > kc){
        neededmoney += (required - kc) * pc;
    }
    if(neededmoney > r){
        return false;
    }
    return neededmoney <= r;




}


int main(){
    string s;
    cin>>s;
    int nb =0;
    int ns =0;
    int nc = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            nb++;
        } else if (s[i] == 'S') {
            ns++;
        } else {
            nc++;
        }
    }
    int kb, ks, kc;
    cin>>kb>>ks>>kc;
    int pb, ps, pc;
    cin>>pb>>ps>>pc;
    long long r;
    cin>>r;
    long long low = 0;
    long long high = 1e13;
    long long answer = 0;

    while(low<=high){
        long long mid = (low+high)/2;
        if(check(mid, nb, ns, nc, kb, ks, kc, pb, ps, pc, r)){
            answer = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }
    cout<<answer;
}