#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> drec(n);
    for(int i = 0; i < n; i++){
        cin >> drec[i];
    }

   if(drec[n-1]==0){
        cout<<"UP";
    }
    else if(drec[n-1]==15){
        cout<<"DOWN";
    }
    else if(n==1){
        cout<<"-1";
    }
    else if(drec[n-1]-drec[n-2]>0){
        cout<<"UP";
    }
    else if(drec[n-1]-drec[n-2]<0){
        cout<<"DOWN";
    }
    return 0;

}