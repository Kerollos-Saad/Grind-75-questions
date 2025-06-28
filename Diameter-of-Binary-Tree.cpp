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

    int dfs(TreeNode* root, int& diam)
    {
        if(!root)
            return 0;

        int l = dfs(root->left, diam);
        int r = dfs(root->right, diam);

        diam = max(diam, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int diam = 0;
        dfs(root, diam);
        return diam;
    }
};