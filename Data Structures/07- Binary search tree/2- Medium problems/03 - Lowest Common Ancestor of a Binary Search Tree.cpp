#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left , p , q);
        }

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right , p , q);
        }

        return root;
    }
};

int main() {

	return 0;
}
/*
    leetCode 235:
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/ss
*/
