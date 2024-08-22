/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Previous;
        ListNode* Current=head;
        if(!head){
            return nullptr;
        }
        int size=0;
        while(Current){
            size++;
            Current=Current->next;
        }
        int pos=size-n+1;
        int curpos=1;
        Current=head;
        Previous=nullptr;
        while(Current){
            if(curpos==pos){
                if(curpos==1){
                    head=Current->next;
                    delete Current;
                    return head;
                }
                Previous->next=Current->next;
                delete Current;
                return head;
            }
            curpos++;
            Previous=Current;
            Current=Current->next;
        }
        return head;
    }
};