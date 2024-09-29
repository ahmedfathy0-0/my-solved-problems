#include <iostream>
#include <vector>
using namespace std;

int haybales(vector <int> v1){
    int n = v1[0];
    int d = v1[1];
    int i = 3;
    while (i<n+2 && d>0){
        if(v1[i]>0)
        {
            v1[i-1]++;
            v1[i]--;
            d--;
            i=3;
        }
        else
        {
            i++;
        }
    }
    return v1[2];
}


int main (){
    int t;
    cin >> t;
    vector <vector<int>> v;
    for(int i = 0; i < t; i++){
        int n, d;
        cin >> n >> d;
        vector <int> v1;
        v1.push_back(n);
        v1.push_back(d);
        for(int j = 0; j < v1[0]; j++){
            int x;
            cin >> x;
            v1.push_back(x);
        }
        v.push_back(v1);
    }

    for(int i = 0; i < t; i++){
        cout << haybales(v[i]) << endl;
    }
    return 0;


}