#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct avlTreeNode {
	int val;
	avlTreeNode* left;
	avlTreeNode* right;
	avlTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(avlTreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}
void balance(avlTreeNode*& root) {
	if (root == NULL) {
		return;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (leftHeight - rightHeight > 1) {

		if (height(root->left->left) < height(root->left->right)) {
			avlTreeNode* temp = root->left;
			root->left = temp->right;
			temp->right = root->left->left;
			root->left->left = temp;
		}

		avlTreeNode* temp = root;
		root = root->left;
		temp->left = root->right;
		root->right = temp;

	}

	else if (rightHeight - leftHeight > 1) {

		if (height(root->right->right) < height(root->right->left)) {
			avlTreeNode* temp = root->right;
			root->right = temp->left;
			temp->left = root->right->right;
			root->right->right = temp;
		}

		avlTreeNode* temp = root;
		root = root->right;
		temp->right = root->left;
		root->left = temp;
	}

	balance(root->left);
	balance(root->right);
}

void insert(avlTreeNode*& root, int val) {
	if (root == NULL) {
		root = new avlTreeNode(val);
		return;
	}
	if (val < root->val) {
		insert(root->left, val);
	}
	else {
		insert(root->right, val);
	}
	balance(root);
}

void avlInsert(avlTreeNode*& root, int val) {
	insert(root, val);
}
void avldelete(avlTreeNode*& root, int val) {
	if (root == NULL) {
		return;
	}
	if (root->val == val) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			avlTreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			avlTreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			avlTreeNode* temp = root->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			root->val = temp->val;
			avldelete(root->right, temp->val);
		}
	}
	else if (val < root->val) {
		avldelete(root->left, val);
	}
	else {
		avldelete(root->right, val);
	}
	balance(root);
}



void printSpace(double n, avlTreeNode*& removed)
{
	for (; n > 0; n--) {
		cout << "\t";
	}
	if (removed == nullptr) {
		cout << " ";
	}
	else {
		cout << removed->val;
	}
}



void print(avlTreeNode*& root)
{
	queue<avlTreeNode*> treeLevel, temp;
	treeLevel.push(root);
	int counter = 0;
	int heightt = height(root) - 1;
	double numberOfElements = pow(2, (heightt+1)) - 1;
	while (counter <= heightt) {
		avlTreeNode* removed = treeLevel.front();
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
	avlTreeNode* root = new avlTreeNode(13);
	avlInsert(root, 10);
	avlInsert(root, 15);
	avlInsert(root, 5);
	avlInsert(root, 11);
	avlInsert(root, 16);
	avlInsert(root, 4);
	avlInsert(root, 6);
	avlInsert(root, 7);
	avldelete(root, 6);

	print(root);
	return 0;

}
