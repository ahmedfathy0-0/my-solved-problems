#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int getminimummoves(vector<string>& A, vector<string>& shifted,int index,int& minmove){
    if(index==shifted.size()){
        return minmove;
    }
    int moves =0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].length();j++){
            string right = shifted[index].substr(0, shifted[index].length()-j);
            string left = A[i].substr(j,A[i].length());
            if(right == left){
                moves+=j;
                break;
            }
            if(j==A[0].length()-1){
                return -1;
            }
        }

    }
    if(moves<minmove){
        minmove=moves;
    }
    return getminimummoves(A,shifted,index+1,minmove);
}


int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    vector <string> shiftedstring;
    string temp = A[0];
    for(int i =0 ; i<A[0].length();i++){
        char startchar = temp[0];
        temp.erase(temp.begin());
        temp.push_back(startchar);
        shiftedstring.push_back(temp);
    }
    int minmax=INT16_MAX;
    cout<< getminimummoves(A,shiftedstring,0,minmax);

    return 0;
}
