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
    int findTilt(TreeNode* root) {
        
    }
private:
    int findTilt(TreeNode* root, int& sumChildren) {
        if (NULL == root) return 0;
        int sumLeft = 0, sumRight = 0;
        int tiltLeft = findTilt(root->left, sumLeft);
        int tiltRight = findTilt(root->right, sumRight);
        sumChildren = sumLeft + sumRight;
        return abs(sumLeft - sumRight) + tilt
    }
};
