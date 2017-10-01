class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        int val = root->val;
        TreeNode* left = root->left, *right = root->right;
        int lc = longestUnivaluePath(left);
        int rc = longestUnivaluePath(right);
        
        if (left != NULL && left->val == val &&
            right != NULL && right->val == val)
            return lc+rc+2;
        if (left != NULL && left->val == val)
            return lc+1 > rc? lc+1: rc;
        if (right != NULL && right->val == val)
            return rc+1 > lc? rc+1: lc;
        return lc > rc? lc: rc;
    }
};
