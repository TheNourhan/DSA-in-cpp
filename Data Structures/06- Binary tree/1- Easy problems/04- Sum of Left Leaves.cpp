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
};



class MySolution{
public:
    bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
			return 0;

        if(root->left){
            if(isLeaf(root->left)){
                sum += root->left->val;

            }
            sumOfLeftLeaves(root->left);
        }
        if (root->right){
            sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

class Solution {
public:
    bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }
	int sumOfLeftLeaves(struct TreeNode *root) {
		if (!root)
			return 0;

		int sum = 0;
		if (isLeaf(root->left))
			sum += root->left->val;

		sum += sumOfLeftLeaves(root->left);
		sum += sumOfLeftLeaves(root->right);

		return sum;
	}
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << Solution().sumOfLeftLeaves(tree.root) << "\n";	// 17

	return 0;
}
/*
    leetCode 404:
    https://leetcode.com/problems/sum-of-left-leaves/
*/

