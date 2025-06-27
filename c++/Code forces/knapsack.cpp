#include <iostream>
#include <vector>
using namespace std;

void knapsack(vector<pair<int,int>> & items, int i,int b,int value ,int &maxval){
    if(i == items.size() || b == 0) {
        maxval = max(maxval, value);
        return;
    }
    if(items[i].first <= b) {
        knapsack(items, i+1, b-items[i].first, value+items[i].second, maxval);
    }
    knapsack(items, i+1, b, value, maxval);
}
int main(){
    int n,b;
    cin>>n>>b;
    vector<pair<int,int>> items(n);
    for(int i =0;i<n;i++){
        cin>>items[i].first>>items[i].second;
    }
    int maxval = 0;
    knapsack(items, 0, b, 0, maxval);
    cout<<maxval<<endl;
}