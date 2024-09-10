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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        if(!head) return res;
        ListNode* temp = head;
        for (int i=0;i<n;i++){
            res[0][i] = temp->val;
            temp = temp->next;
            if(!temp) return res;
        }
        int i = 1;
        int j = n-1;
        int icount = 0;
        int jcount = 0;

        bool flag = false;
        bool flag1 = true;

        int jdecrement = 1;
        int idecrement = 1;


        while(true){
            if(!temp) return res;
            res[i][j] = temp->val;
            temp= temp->next;
            if(icount%2==0){
                if(i==m-1){
                    flag=true;
                }else
                {
                i++;
                }
            }else{
                if(i==idecrement-1){
                    flag=true;
                }
                else {
                    i--;
                }

            }
            if(flag){
                icount++;
                if(jcount%2==0){
                    j=n-(++jdecrement);
                }
                else{
                    j=0+(jdecrement)-1;
                }

                while(true){
                    if(!temp) return res;
                    res[i][j] = temp->val;
                    temp= temp->next;
                    if(jcount%2==0){
                        if(j==jdecrement-2){
                            flag=false;
                            jcount++;
                            i=m-(++idecrement);
                            break;
                        }
                        else{
                            j--;
                        }
                    }else{
                        if(j==n-jdecrement){
                            flag=false;
                            jcount++;
                            i=idecrement;
                            break;
                        }
                        else{
                           j++;
                        }
                    }

                }

            }



        }

    }
};

int main (){

    int m = 3;
    int n = 5;
    int listsize =25;
    ListNode* head = new ListNode(3);
    ListNode* temp = head;
    for(int i=0;i<listsize-1;i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    Solution s;
    vector<vector<int>> res = s.spiralMatrix(m,n,head);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;

    }
    return 0;
}