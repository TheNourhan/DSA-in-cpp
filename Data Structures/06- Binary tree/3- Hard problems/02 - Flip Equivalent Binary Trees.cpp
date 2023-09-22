#include <iostream>
#include <sstream>	// ostringstream
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

class Solution {
public:
    string toStr(int n) {
        // Convert integer to string
        ostringstream oss;
        oss << n;
        return oss.str();
    }

	string _parenthesize_canonical(TreeNode *root) {
		if (!root)
			return "()";

		string repr = "(" + toStr(root->val);

		vector<string> v;

		if (left)
			v.push_back(_parenthesize_canonical(root->left));
		else
			v.push_back("()");

		if (right)
			v.push_back(_parenthesize_canonical(root->right));
		else
			v.push_back("()");

		sort(v.begin(), v.end());
		for (int i = 0; i < (int) v.size(); ++i)
			repr += v[i];

		repr += ")";

		return repr;
	}
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return _parenthesize_canonical(root1) == _parenthesize_canonical(root2);
    }
};

int main() {

	cout << "\n\nbye\n";

	return 0;
}
/*
    leetCodoe 951:
    https://leetcode.com/problems/flip-equivalent-binary-trees/
*/
