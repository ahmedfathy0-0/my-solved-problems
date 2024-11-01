#include <iostream>
#include <vector>
#include <cmath>
using namespace std;




int main (){
    int N;
    cin >>N;
    vector <vector <int> > pairs (N,vector<int>(2));
    for(int i =0;i<N; i++){
        cin>>pairs[i][0]>>pairs[i][1];
    }
    int min =INT16_MAX;
    for(int i =0;i<N;i++){
        for(int j = i+1;j <N ;j++){
            int distance = sqrt(pow(pairs[i][0]-pairs[j][0],2)+pow(pairs[i][1]-pairs[j][1],2));
                    if(distance<min){
                        min=distance;
                    }
        }
    }
    cout<<min;
    return 0;

}