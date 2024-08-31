#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = preorder.size() == 0 ? nullptr : new TreeNode(preorder[0]);

        for (int i =0 ; i < preorder.size();i++){
            if(inorder[i]==root->val){
                vector<int> left_preorder(preorder.begin()+1, preorder.begin()+i+1);
                vector<int> right_preorder(preorder.begin()+i+1, preorder.end());
                vector<int> left_inorder(inorder.begin(), inorder.begin()+i);
                vector<int> right_inorder(inorder.begin()+i+1, inorder.end());
                root->left = buildTree(left_preorder, left_inorder);
                root->right = buildTree(right_preorder, right_inorder);
                break;
            }

        }
        return root;
    }
};

void print(TreeNode* root){
    if(root == nullptr){
        cout<<"null,";
        return;
    }
    cout<<root->val<<",";
    print(root->left);
    print(root->right);
}

int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *root =s.buildTree(preorder, inorder);
    //now lets print the tree like this Output: [3,9,20,null,null,15,7]
    print(root);
    return 0;
}