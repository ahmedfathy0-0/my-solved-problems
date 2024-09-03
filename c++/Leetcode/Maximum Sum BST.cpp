
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int maxSum = 0;
        int sum = 0;
        int max = INT_MIN;
        bool isBST;

        if(root->left && root->left->val > root->val || root->right && root->right->val < root->val){
            isBST = false;
        }
        else
            isBST = true;

        int a=0;
        int b=0;
        dfs(root, sum, max, isBST,a,b);
        if(max < 0) return 0;
        return max;
    }
    void dfs(TreeNode* root, int& sum, int& max, bool& isBST,int& Max , int& Min ){
        if(!root){
            isBST = true;
            Max = 0;
            Min = 0;
            return ;
        }

        dfs(root->left, sum, max, isBST, Max, Min);
        int leftSum = sum;
        int leftMax = Max;
        int leftMin = Min;
        bool leftIsBST = isBST;

        sum = 0;
        dfs(root->right, sum, max, isBST, Max, Min);
        int rightSum = sum;
        int rightMax = Max;
        int rightMin = Min;
        bool rightIsBST = isBST;


        if(leftIsBST && rightIsBST){
            if(root->left && root->left->val >= root->val || root->right && root->right->val <= root->val){
                isBST = false;
                return ;
            }
            isBST = true;
            if(leftMax ==0){
                leftMax = INT_MIN;
            }
            if(rightMin == 0){
                rightMin = INT_MAX;
            }
            if(leftMax < root->val && rightMin > root->val){
                sum = leftSum + rightSum + root->val;
                max = max > sum ? max : sum;
            }
            else{
                isBST = false;
            }

        }
        else{
            isBST = false;
        }
        Max = getthemaxminof3(root->val, leftMax, rightMax, true);
        Min = getthemaxminof3(root->val, leftMin, rightMin, false);


    }
    int getthemaxminof3(int a, int b, int c ,bool mode){
        if(mode){
            return a > b ? (a > c ? a : c) : (b > c ? b : c);
        }
        else{
            return a < b ? (a < c ? a : c) : (b < c ? b : c);
        }
    }
};

int main (){
    // [1,null,10,-5,20]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(-5);
    root->right->right = new TreeNode(20);

    Solution s;
    cout << s.maxSumBST(root);
    return 0;
}