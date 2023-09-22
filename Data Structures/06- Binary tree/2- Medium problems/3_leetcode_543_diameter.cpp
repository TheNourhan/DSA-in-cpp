#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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

bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return _diameterOfBinaryTree(root).first;
    }

	pair<int, int> _diameterOfBinaryTree(TreeNode* root) {	// return diam & height
		pair<int, int> res = make_pair(0, 0);

		if (isLeaf(root))
			return res;

		pair<int, int> left_diam = make_pair(0, 0);
		pair<int, int> right_diam = make_pair(0, 0);

		// Diameter either pass with the root or not: 2 cases
		// diameter if passes with me: then it is the longest height from left to me to right height

		if (root->left)
			left_diam = _diameterOfBinaryTree(root->left), res.first += 1 + left_diam.second;	// edge + its height
		if (root->right)
			right_diam = _diameterOfBinaryTree(root->right), res.first += 1 + right_diam.second;

		// diameter if in one of my children subtrees
		res.first = max(res.first, max(left_diam.first, right_diam.first));

		// normal height computation
		res.second = 1 + max(left_diam.second, right_diam.second);

		return res;
	}
};

class MySolution{
private:
    int max_diameter_so_far = 0;

    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);

        max_diameter_so_far = max(max_diameter_so_far, left_height + right_height);

        return 1 + max(left_height, right_height);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        height(root);
        return max_diameter_so_far;
    }
};

int main() {

	 BinaryTree tree(1);
	 tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	 tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	 tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	 tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	 auto results = Solution().diameterOfBinaryTree(tree.root);
     cout<<results<<"\n";

	 auto MyResults = MySolution().diameterOfBinaryTree(tree.root);
	 cout<<MyResults<<"\n";


	cout << "\nbye\n";
	return 0;
}

/*
    leetCode 543:
    https://leetcode.com/problems/diameter-of-binary-tree/description/
*/
