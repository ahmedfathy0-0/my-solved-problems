#include <iostream>
using namespace std;
#include <vector>

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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        flatten(root->left);
        TreeNode* temp = root->right;
        flatten(root->right);
        if(root->left == nullptr) return;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* temp1 = root->right;
        while(temp1->right!=nullptr){
            temp1 = temp1->right;
        }
        temp1->right = temp;
        return;



    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    s.flatten(root);
    while(root!=nullptr){
        cout<<root->val<<",";
        root = root->right;
    }
    return 0;
}