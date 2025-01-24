#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void sum(TreeNode *root, int target, int amount,bool flag)
{
    if (root == NULL)
    {
        if(!flag){
            cout<<0<<" ";
        }
        return;
    }
    if (root->val == target)
    {
        flag=true;
        cout << amount + root->val << " ";
    }
    sum(root->left, target, amount + root->val,flag);
    sum(root->right, target, amount + root->val,flag);
}
int main()
{
    int n;
    cin >> n;
    vector<TreeNode *> nodes(n, NULL);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        nodes[i] = new TreeNode(v);
    }
    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        char D;
        int P, C;
        cin >> D >> P >> C;
        if (D == 'L')
        {
            nodes[P]->left = nodes[C];
        }
        else
        {
            nodes[P]->right = nodes[C];
        }
    }
    int nq;
    cin >> nq;
    vector<int> q(nq);
    for (int i = 0; i < nq; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < nq; i++)
    {
        if (nodes[0] == nullptr)
        {
            cout << 0 << endl;
            break;
        }
        sum(nodes[0], q[i], 0,false);
        cout << endl;
    }
    return 0;
}