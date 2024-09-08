#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       vector<ListNode*> res(k,NULL);
       vector,int> count(k,0);
        ListNode* temp = head;
         int i = 0;
       while(temp){
           count[i%k]++;
           temp = temp->next;
            i++;
       }
        temp = head;
        ListNode* prev = NULL;
        for (int i =0;i<k; i++){
            
               for(int j=0 ; j<count[i] ; j++){
                     if(!res[i]){
                          res[i] = temp;
                     }
                     prev = temp;
                     temp = temp->next;
               }
            if(prev){
                prev->next = NULL;
            }

        }
    
    
    }
        
};
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);


    Solution s;
    vector<ListNode*> res = s.splitListToParts(head,3);
    for(auto i:res){
        while(i){
            cout<<i->val<<" ";
            i=i->next;
        }
        cout<<endl;
    }
    return 0;
}

