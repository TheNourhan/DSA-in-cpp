#include <iostream>
#include <cassert>
#include <vector>
#include<cmath>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};


struct BinaryTree {
	TreeNode* root { };
	BinaryTree(int root_value) : root(new TreeNode(root_value)) {
	}
	int numOfNode=1;

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode* current = this->root;
		//numOfNode++;
		// iterate on the path, create all necessary TreeNodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left){
					current->left = new TreeNode(values[i]);
					numOfNode++;
				}
				else
					assert(current->left->val == values[i]);
				current = current->left;
			} else {
				if (!current->right){
					current->right = new TreeNode(values[i]);
					numOfNode++;
				}
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}

	void print_postorder(TreeNode* current) {
        if(!current)
            return;
        print_postorder(current->left);
        print_postorder(current->right);
        cout << current->val << " ";
    }

	void _print_inorder(TreeNode* current) {
		if (!current)
			return;
		_print_inorder(current->left);
		cout << current->val << " ";
		_print_inorder(current->right);
	}

    void print_preorder(TreeNode* current) {
        if(!current)
            return;
        cout << current->val << " ";
        print_preorder(current->left);
        print_preorder(current->right);
    }

	void print_inorder() {
		_print_inorder(root);
		cout << "\n";
	}

	int mx=0;
	int MaxValue_HW(TreeNode* current) {//MY Solution
        if(!current)
            return mx;
        if(current->val >= mx){
            mx = current->val;
        }
        MaxValue0(current->left);
        MaxValue0(current->right);
    }

    int MaxValue(TreeNode *root){
		if(!root)
			return 0;

		int res = root->val;
		if (root->left)
			res = max(res, MaxValue(root->left));
		if (root->right)
			res = max(res, MaxValue(root->right));
		return res;
	}

    bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }

};
int main() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	cout<<tree.MaxValue(tree.root)<<"\n";

	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	cout<<tree.MaxValue(tree.root)<<"\n";

	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	cout<<tree.MaxValue(tree.root)<<"\n";

	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
	cout<<tree.MaxValue(tree.root)<<"\n";

	tree.print_inorder();
	// 7 4 8 2 5 9 1 3 10 6

	return 0;
}


