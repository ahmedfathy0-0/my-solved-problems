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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* temp = head;
        listNode* next = head->next;
        // first solution
        // while(next){
        //     int gcd = __gcd(temp->val,next->val);
        //     ListNode* newNode = new ListNode(gcd);
        //     newNode->next = next;
        //     temp->next = newNode;
        //     temp = next;
        //     next = next->next;

        // }

        // second solution
        // while(next){
        //     int small= (temp->val<next->val)?temp->val:next->val;
        //     int big = (temp->val>next->val)?temp->val:next->val;
        //     for(int i= small;i>0;i--){
        //         if(small%i==0 && big%i==0){
        //             ListNode* newNode = new ListNode(i);
        //             newNode->next = next;
        //             temp->next = newNode;
        //             temp = next;
        //             next = next->next;
        //             break;
        //         }
        //     }
        // }

        // third solution

         while(next){
            int small= (temp->val<next->val)?temp->val:next->val;
            int big = (temp->val>next->val)?temp->val:next->val;
            while(big%small!=0){
                int temp = big;
                big = small;
                small = temp%small;
            }
            int gcd = small;
            ListNode* newNode = new ListNode(gcd);
            newNode->next = next;
            temp->next = newNode;
            temp = next;
            next = next->next;
         }
        return head;

    }

};

int main(){
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode* res = s.insertGreatestCommonDivisors(head);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}