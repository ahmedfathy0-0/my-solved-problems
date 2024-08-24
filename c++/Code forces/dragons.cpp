#include <iostream>
#include <vector>

using namespace std;

struct Dragon {
    int Strength, Bonus;
};
void heapify(vector<Dragon>& a, int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l].Strength > a[largest].Strength) {
        largest = l;
    }
    if (r < n && a[r].Strength > a[largest].Strength) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}
void strengthheapsort(vector<Dragon>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main (){
    int mystrength;
    cin >> mystrength;
    int n;
    cin >> n;
    vector<Dragon> dragons(n);
    if(n==0){
        cout<<"YES"<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> dragons[i].Strength >> dragons[i].Bonus;
    }
    strengthheapsort(dragons);

    for (int i=0; i<n;i++){
        if(mystrength>dragons[i].Strength){
            mystrength+=dragons[i].Bonus;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
