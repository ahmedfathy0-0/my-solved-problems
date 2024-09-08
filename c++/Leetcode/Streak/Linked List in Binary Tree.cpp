#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool dfs(ListNode* node, TreeNode* root) {
        if (!node) return true;
        if (!root) return false;

        if (root->val == node->val) {
            return dfs(node->next, root->left) || dfs(node->next, root->right);
        }

        return false;
    }
};

int main (){

    ListNode* head = new ListNode(2);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);

    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);


    Solution s;
    std::cout << s.isSubPath(head,root);
    return 0;

}