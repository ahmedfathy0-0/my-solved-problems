#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxValue(int i , vector<vector<int>> A,int W,int sumvalue ,int & max){
    if(W < 0){
        return 0;
    }
    if(sumvalue > max){
        max = sumvalue;
    }
    if(i == A.size()){
        return 0;
    }


    getMaxValue(i+1,A,W-A[i][0],sumvalue+A[i][1],max);
    getMaxValue(i+1,A,W,sumvalue,max);
    if(i==0){
        return max;
    }
    return 0;
}

int main() {
    int W;
    cin >> W;
    int N;
    cin >> N;
    vector<vector<int>> A(N,vector<int>(2));
    for(int i =0;i<N;i++){
        cin >> A[i][0] >> A[i][1];
    }
    int max = 0;
    cout<<getMaxValue(0,A,W,0,max)<<endl;
    return 0;
}
