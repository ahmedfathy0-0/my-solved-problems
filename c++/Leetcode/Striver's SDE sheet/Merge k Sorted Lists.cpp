#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* output = lists[0];
        for(int i=1;i<lists.size();i++){
            output =  merge2Nodes(output,lists[i]);
        }
        return output;

    }
    ListNode* merge2Nodes(ListNode* l1, ListNode* l2){
        ListNode* output=new ListNode();
        ListNode* temp=output;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1!=NULL){
            temp->next=l1;
        }
        if(l2!=NULL){
            temp->next=l2;
        }
        return output->next;

    }

};
int main (){
    Solution s;
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(5);
    //list 1 = 1->4->5
    ListNode* l2=new ListNode(1);
    l2->next=new ListNode(3);
    l2->next->next=new ListNode(4);
    //list 2 = 1->3->4
    ListNode* l3=new ListNode(2);
    l3->next=new ListNode(6);
    //list 3 = 2->6
    vector<ListNode*> lists={l1,l2,l3};
    ListNode* output=s.mergeKLists(lists);
    //output = 1->1->2->3->4->4->5->6
    while(output!=NULL){
        cout<<output->val<<" ";
        output=output->next;
    }
    cout<<endl;
    return 0;
}
