#include <iostream>
#include <sstream>	// ostringstream
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

struct BinaryTree {
	TreeNode *root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode *current = this->root;
		// iterate on the path, create all necessary TreeNodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new TreeNode(values[i]);
				else
					assert(current->left->val == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new TreeNode(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}

};

class Solution {
public:
    bool _isSymmetric(TreeNode* left,TreeNode* right) {
        if(!left && !right){
            return true;
        }

        if(left && !right || !left && right || left->val != right->val){
            return false;
        }

        return _isSymmetric(left->left,right->right) && _isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root){
        if(!root)
            return false;

         return _isSymmetric(root->left, root->right);
    }
};


int main() {

    BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << Solution().isSymmetric(tree.root) << "\n";

	cout << "\n\nbye\n";

	return 0;
}
/*
    leetCode 101:
    https://leetcode.com/problems/symmetric-tree/
*/

