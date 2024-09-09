/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> arr;
    getSortedArray(root, arr);
    return buildBST(arr, 0, arr.size() - 1);
  }
private:
  void getSortedArray(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;
    getSortedArray(root->left, arr);
    arr.push_back(root->val);
    getSortedArray(root->right, arr);
  }
  TreeNode* buildBST(vector<int>& arr, int l, int r) {
    if ( l > r ) return nullptr;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildBST(arr, l, mid - 1);
    root->right = buildBST(arr, mid + 1, r);
    return root;
  }
};
