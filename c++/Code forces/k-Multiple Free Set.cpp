#include <iostream>
using namespace std;
#include <vector>

void maxheapify(vector<int> &a, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(a[i], a[largest]);
        maxheapify(a, n, largest);
    }


}
void heapsort(vector<int> &a, int n){
    for(int i = n/2-1; i>=0; i--){
        maxheapify(a, n, i);
    }
    for(int i = n-1; i>0; i--){
        swap(a[0], a[i]);
        maxheapify(a, i, 0);
    }
}
bool binarysearch(vector<int> &a, int n, int k){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==k){
            return true;
        }
        else if(a[mid]>k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return false;
}
int main (){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    heapsort(a, n);
    vector <int> largsubset;
    for(int i = n-1; i>=0; i--){
        largestsubset.push_back(a[i]);
        if (binarysearch(largsubset, largsubset.size(), a[i]/k)){
            largsubset.pop_back();
        }
        
    }
    cout<<largsubset.size();
    return 0;
}