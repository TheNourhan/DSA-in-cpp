#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
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

// Accepted solution on leefcode
class Solution {
public:

    bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }

    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);

		int level=0,missing_node=0;
		bool leaf=0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			if(sz != pow(2,level) && leaf!=1){
                return false;
			}

			while(sz--) {
				TreeNode*cur = nodes_queue.front();
				nodes_queue.pop();

				if(missing_node==2 && cur->left){
                    return false;
                }
				if (cur->left)
					nodes_queue.push(cur->left);
                else
                    missing_node =1;
             ///////////////////////////////////////////
                if(missing_node && cur->right){
                    return false;
                }
				if (cur->right)
					nodes_queue.push(cur->right);
                else
                    missing_node =2;

                if(isLeaf(cur->left) || isLeaf(cur->right)) leaf=1;
			}
			level++;
		}
		return true;
    }
};

void test1() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7 ,14}, { 'R', 'R' ,'L'});
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

	auto results = Solution().isCompleteTree(tree.root);
	cout<<results<<"\n";
}

int main() {
	test1();

	cout << "bye\n";

	return 0;
}
