#include <iostream>
#include <sstream>	// ostringstream
#include <cassert>
#include <vector>
#include <map>
using namespace std;

string toStr(int n) {
	// Convert integer to string
	ostringstream oss;
	oss << n;
	return oss.str();
}

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
     bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }

    string _parenthesize(TreeNode *root, map<string,int>&m) {
		if (!root)
			return "()";

		string repr = "(" + toStr(root->val);

		if (root->left)
			repr += _parenthesize(root->left,m);
		else
			repr += "()";	// null: no child

		if (root->right)
			repr += _parenthesize(root->right,m);
		else
			repr += "()";	// null: no child
		repr += ")";

		if(!isLeaf(root)){
            m[repr]++;
		}
		return repr;
	}

	void print_duplicate_subtrees(TreeNode* root){
	    map<string,int>m;
	    _parenthesize(root, m);
        for(auto mm:m){
            if(mm.second > 1){
                cout<<mm.first<<"\n";
            }
        }
	}

};

void test0(){
    BinaryTree tree(1);

	tree.add( { 2, 3 }, { 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'R', 'R', 'R' });
	tree.add( { 4, 2, 3 }, { 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'L', 'R', 'R'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'R', 'L'});

    Solution().print_duplicate_subtrees(tree.root);
}

int main() {

	test0();

	cout << "\n\nbye\n";

	return 0;
}


