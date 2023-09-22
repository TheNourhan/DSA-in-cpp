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

class Solution{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,(int)nums.size()-1);
    }

     TreeNode* sortedArrayToBST(vector<int>& val, int start, int end) {
        if(start > end)
            return nullptr;

        int m = (start+end)/2;
        TreeNode* root = new TreeNode(val[m]);
        root->left = sortedArrayToBST(val,start,m-1);
        root->right = sortedArrayToBST(val, m+1, end);

        return root;
    }
};

int main() {

    vector<int> v {1,2,3,4,5,6,7,8};

    Solution s;

    s.sortedArrayToBST(v);

	return 0;
}
/*
    leetCode 108:
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

