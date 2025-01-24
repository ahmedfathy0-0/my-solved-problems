#include  <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct RBTreeNode {
    int val;
    RBTreeNode* left;
    RBTreeNode* right;
    RBTreeNode* parent;
    int color;//0 for black, 1 for red
    RBTreeNode(int x, int c, RBTreeNode* p) : val(x), color(c), parent(p), left(NULL), right(NULL) {}
};
int height(RBTreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}
void leftRotate(RBTreeNode*& root, RBTreeNode*& x) {
    RBTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
void rightRotate(RBTreeNode*& root, RBTreeNode* x) {
    RBTreeNode* y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}


void balanceRB(RBTreeNode*& root, RBTreeNode* z) {
    while (z->parent != NULL && z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode* y = z->parent->parent->right;
            if (y != NULL && y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(root, z->parent->parent);
            }
        }
        else {
            RBTreeNode* y = z->parent->parent->left;
            if (y != NULL && y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    root->color = 0;

}

void insert(RBTreeNode*& root, RBTreeNode*& z, RBTreeNode* parent, int val) {
    if (z == NULL) {
        z = new RBTreeNode(val, 1, NULL);
        z->parent = parent;
        balanceRB(root, z);
        return;
    }
    if (val < z->val) {
        insert(root, z->left, z, val);
    }
    else {
        insert(root, z->right, z, val);
    }
}

void RBInsert(RBTreeNode*& root, int val) {
    insert(root, root, NULL, val);
}



void printSpace(double n, RBTreeNode*& removed)
{
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == nullptr) {
        cout << " ";
    }
    else {
        cout << removed->val << "(" << removed->color << ")";
    }
}



void print(RBTreeNode*& root)
{
    queue<RBTreeNode*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int heightt = height(root) - 1;
    double numberOfElements = pow(2, (heightt + 1)) - 1;
    while (counter <= heightt) {
        RBTreeNode* removed = treeLevel.front();
        treeLevel.pop();
        if (temp.empty()) {
            printSpace(numberOfElements
                / pow(2, counter + 1),
                removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                removed);
        }
        if (removed == nullptr) {
            temp.push(nullptr);
            temp.push(nullptr);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            counter++;
        }
    }
}
int main() {
    RBTreeNode* root = new RBTreeNode(11, 0, NULL);
    RBInsert(root, 2);
    RBInsert(root, 14);
    RBInsert(root, 1);
    RBInsert(root, 7);
    RBInsert(root, 15);
    RBInsert(root, 5);
    RBInsert(root, 8);
    RBInsert(root, 4);
    return 0;

}
