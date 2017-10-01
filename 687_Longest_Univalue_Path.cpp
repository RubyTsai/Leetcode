/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Ex1:                                Ex2:
    Input:                              Input:
              5                                 1
             / \                               / \
            4   5                             4   5
           / \   \                           / \   \
          1   1   5    Output: 2            4   4   5   Output: 2
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        lp = 0;
        helper(root);
        return lp;
    }
private:
    int lp;
    int helper(TreeNode* root) {
        int val = root->val;
        TreeNode* lc = root->left, *rc = root->right;
      
        int l = lc? helper(lc): 0;
        int r = rc? helper(rc): 0;
        
        l = (lc && lc->val == val)? ++l: 0; 
        r = (rc && rc->val == val)? ++r: 0;
        
        lp = max(lp, l+r);
        return max(l, r);
    }
};
