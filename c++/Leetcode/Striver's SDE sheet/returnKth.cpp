#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->hsort(nums);
        return nums[k];
    }
    void heaoify(vector<int>& nums,int i,int n){
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        if(l<n && nums[l]<nums[largest]){
            largest=l;
        }
        if(r<n && nums[r]<nums[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heaoify(nums,largest,n);
        }
    }
    void hsort(vector<int>& nums){
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heaoify(nums,i,n);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heaoify(nums,0,i);
        }
    }

};

int main(){
    Solution s;
    vector<int> nums={3,2,1,5,6,4};
    cout<<s.findKthLargest(nums,2)<<endl;
    return 0;
}