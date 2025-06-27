#include<iostream>
using namespace std;
int ans = 0;
void yf(int s, int e){
    if(s>e){
        return;
    }
    if(s==e){
        ans++;
        return;
    }
    yf(s+1,e);
    yf(s+2,e);
    yf(s+3,e);
}

int main(){
    int s,e;
    cin>>s>>e;
    yf(s,e);
    cout<<ans;
}