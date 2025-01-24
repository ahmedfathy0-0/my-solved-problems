#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
void BFS_vector(TreeNode* root,vector<TreeNode*> &v){
    if(root == NULL){
        return ;
    }
    queue<TreeNode*> q;
    q.push(root);
    v.push_back(root);
    q.push(NULL);
    v.push_back(NULL);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node == NULL&&v[v.size()-1] != NULL){
            q.push(NULL);
            v.push_back(NULL);
        }
        else if(node != NULL){
            if(node->left != NULL){
                q.push(node->left);
                v.push_back(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
                v.push_back(node->right);
            }
        }
    }

}
int getmin_level(vector<TreeNode*>&v,int level){
    int min = INT_MAX;
    int count = 0;
    if(level == 0){
        return v[0]->val;
    }
    for(size_t i = 0; i < v.size(); i++){
        if(v[i] == NULL){
            if(count == level){
                return min;
            }
            count++;
            min = INT_MAX;
        }
        else{
            if(v[i]->val < min){
                min = v[i]->val;
            }
        }
    }
    return min;
}

int main(){
    int n;
    cin >> n;
    vector<TreeNode*> nodes(n);
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        nodes[i] = new TreeNode(v);
    }
    int E;
    cin >> E;
    for(int i = 0; i < E; i++){
        char D;
        int P, C;
        cin >> D >> P >> C;
        if(D== 'L'){
            nodes[P]->left = nodes[C];
        }
        else{
            nodes[P]->right = nodes[C];
        }
    }
    TreeNode* root = nodes[0];
    int h = height(root);
    int L = root->val%h;
    vector<TreeNode*> v;
    BFS_vector(root,v);
    int K = getmin_level(v,L)%h;
   if(K==0){
       K=1;
   }
    int count = 0;
    int step = 0;
    int sum = 0;
    for(size_t i = 0; i < v.size(); i++){
        if(v[i] == NULL){
            if(count == step){
                cout << sum;
                step+=K;
            }
            count++;
            sum = 0;
        }
        else{
            sum += v[i]->val;
        }
    }
    return 0;
}