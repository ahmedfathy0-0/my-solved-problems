#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int main()
{
    int ll;
    cin >> ll;
    vector<int> levels(ll);
    for (int i = 0; i < ll; i++)
    {
        cin >> levels[i];
    }

    int n;
    cin >> n;
    vector<TreeNode *> Nodes(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        Nodes[i] = new TreeNode(v);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char D;
        int P, C;
        cin >> D >> P >> C;
        if (D == 'L')
        {
            Nodes[P]->left = Nodes[C];
        }
        else
        {
            Nodes[P]->right = Nodes[C];
        }
    }
    unordered_map<int, vector<int>> mp;
    if (Nodes[0] != nullptr)
    {
        TreeNode *root = Nodes[0];
        queue<TreeNode *> q;
        mp[0] = {Nodes[0]->val};
        q.push(root);
        q.push(NULL);
        int i = 1;
        TreeNode* prev= nullptr;
        TreeNode *node = Nodes[0];
        while (!q.empty())
        {
            prev = node;
            node = q.front();
            q.pop();
            if (node == NULL&& prev!=NULL)
            {
                q.push(NULL);
                i++;
            }
            else if (node != NULL)
            {
                if (node->left != NULL)
                {
                    q.push(node->left);
                    mp[i].push_back(node->left->val);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                    mp[i].push_back(node->right->val);
                }
            }
        }
    }
    for (int i = 0; i < ll; i++)
    {
        int size = mp.find(levels[i])->second.size();
        for (int j = 0; j < size; j++)
        {
            cout << mp.find(levels[i])->second[j] << " ";
        }
        cout << endl;
    }
    return 0;
}