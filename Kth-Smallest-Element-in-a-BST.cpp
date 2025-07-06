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
    int pos = 0;
    void recKthSmallest(TreeNode* root, int k, int& res)
    {
        if(root == nullptr) return;
        
        recKthSmallest(root->left, k, res);
        pos++;
        if(pos == k){
            res = root->val;
            return;
        }

        recKthSmallest(root->right, k, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;
        recKthSmallest(root,k,res);
        return res;
    }
};