#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int median;
        cin >> median;
        if(n==1){
            cout<<1<<endl;
        }
        else if(median==1||n==median){
            cout<<-1<<endl;
        }
        else{
            cout<<3<<" ";
            if((median-1)%2 == 0){
                cout<< 1 << " " << median-1 << " " << median+2 ;
            }
            else{
                cout<< 1 << " " << median << " " << median+1;
            }
            cout<<endl;
        }
        

    }
    return 0;
}