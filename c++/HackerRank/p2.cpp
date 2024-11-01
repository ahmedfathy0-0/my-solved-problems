#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector <int> products(N);
    for(int i=0;i<N;i++){
        cin>>products[i];
    }
    int max=INT16_MIN;
    for(int i =0;i<N;i++){
        products[i]++;
        int product=1;
        for(int j=0;j<N;j++){
            product*=products[j];
        }
        if(product>max){
            max =product;
        }
        products[i]--;
    }
    cout<<max;
    return 0;
}
