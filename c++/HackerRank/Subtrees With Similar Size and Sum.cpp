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

int changesum(TreeNode* root,vector<vector<int>>& s,int m){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        int size =1;
        if(size>m){
            vector<int> temp={root->val,size};
            s.push_back(temp);

        }
        return size;
    }
    int size1 =changesum(root->left,s,m);
    int size2 =changesum(root->right,s,m);
    int sum=root->val;
    if(root->left != NULL){
        sum += root->left->val;
    }
    if(root->right != NULL){
        sum += root->right->val;
    }
    root->val = sum;
    int size = size1 + size2 + 1;
    if(size>m){
        vector<int> temp={root->val,size};
        s.push_back(temp);
    }
    return size;
}



int main(){
    int n,m;
    cin >> n >> m;
    vector<TreeNode*> nodes(n,NULL);
    vector<vector<int>> v;
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

    changesum(nodes[0],v,m);
    for(int i = 0; i < v.size(); i++){
        int existance=1;
        for(int j = i+1; j < v.size(); j++){
            if(v[i][0] == v[j][0] && v[i][1] == v[j][1]){
                existance ++;
            }
        }
        if(existance >=2){
            cout << 1;
            return 0;
        }

    }
    cout << 0;

    return 0;
}
