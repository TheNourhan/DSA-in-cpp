#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
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
};


bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
}


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){

        vector<vector<int>>res;

        if (!root)
			return res;

        deque<TreeNode*> nodes_queue;
		nodes_queue.push_front(root);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();
			vector<int>line;

			if(level%2==0)
                while(sz--){
                    TreeNode*cur = nodes_queue.front();
                    nodes_queue.pop_front();

                    line.push_back(cur->val);

                    if (cur->left)
                        nodes_queue.push_back(cur->left);
                    if (cur->right)
                        nodes_queue.push_back(cur->right);
                }

			if(level%2!=0)
                while(sz--){
                    TreeNode*cur = nodes_queue.back();
                    nodes_queue.pop_back();

                    line.push_back(cur->val);

                    if (cur->right)
                        nodes_queue.push_front(cur->right);
                    if (cur->left)
                        nodes_queue.push_front(cur->left);
                }
            res.push_back(line);
			level++;
		}

		return res;
    }
};
int main() {
	BinaryTree tree(3);
	tree.add( { 9 }, { 'L' });
	tree.add( { 20, 7 }, { 'R', 'R' });
	tree.add( { 20, 15 }, { 'R', 'L' });

	auto results = Solution().zigzagLevelOrder(tree.root);

	for (auto row : results) {
		for (auto col : row)
			cout << col << " ";
		cout << "\n";
	}

	/*
	 BinaryTree tree(1);
	 tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	 tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	 tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	 tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	 auto results = Solution().zigzagLevelOrder(tree.root);

	 for (auto row : results) {
	 for (auto col : row)
	 cout << col << " ";
	 cout << "\n";
	 }
	 */

	cout << "bye\n";

	return 0;
}

/*
    leetCode 103:
    https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/
