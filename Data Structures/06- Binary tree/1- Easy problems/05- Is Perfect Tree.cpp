#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
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

	void _printInorder(TreeNode *current) {
		if (!current)
			return;
		_printInorder(current->left);
		cout << current->val << " ";
		_printInorder(current->right);
	}

	void printInorder() {
		_printInorder(root);
		cout << "\n";
	}
};

bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
}

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (!root)
			return 0;
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		return max(l, r) + 1;
	}

	bool is_perfect(TreeNode *root, int h) {
		if (isLeaf(root))
			return h == 0;	// All leaves must be on the same last level

		if (!root->left && root->right || root->left && !root->right)
			return false;	// one child!

		// perfect on level h is perfect on h-1 for children
		return is_perfect(root->left, h - 1) && is_perfect(root->right, h - 1);
	}

	bool is_perfect(TreeNode *root) {
		return is_perfect(root, maxDepth(root) - 1);
	}

	int total_nodes(TreeNode *root) {
		if(!root)
			return 0;
		return 1 + total_nodes(root->left) + total_nodes(root->right);
	}


	bool is_perfect_fomula(TreeNode *root) {
		int h = maxDepth(root) - 1;
		int n = total_nodes(root);
		return pow(2, h + 1) - 1 == n;
	}
};

int main() {	// rename like main1 for leetcode
	BinaryTree tree(1);

	assert(Solution().is_perfect(tree.root) == 1);

	tree.add( { 2 }, { 'L' });
	assert(Solution().is_perfect(tree.root) == 0);

	tree.add( { 3 }, { 'R' });
	assert(Solution().is_perfect(tree.root) == 1);

	tree.add( { 3, 6}, { 'R', 'R' });
	tree.add( { 3, 14 }, { 'R', 'L'});
	assert(Solution().is_perfect(tree.root) == 0);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });
	assert(Solution().is_perfect(tree.root) == 0);

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	assert(Solution().is_perfect(tree.root) == 0);

	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	assert(Solution().is_perfect(tree.root) == 1);	// now 8 leaf nodes

	cout<<"bye";

	return 0;
}

