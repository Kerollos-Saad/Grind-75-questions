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

    TreeNode* recAncestor(TreeNode* root, int pVal, int qVal) {
        if (root == nullptr) return nullptr;
        
        if (pVal < root->val && qVal < root->val) {
            return recAncestor(root->left, pVal, qVal);
        }
        
        if (pVal > root->val && qVal > root->val) {
            return recAncestor(root->right, pVal, qVal);
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return recAncestor(root, p->val, q->val);
    }
};