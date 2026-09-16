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
    bool helper(TreeNode* root,int sum,int tgt){
        if(root==NULL) return false;
        sum+=root->val;
        if(sum==tgt && root->left==NULL && root->right==NULL) return true;
        return (helper(root->left,sum,tgt) || helper(root->right,sum,tgt));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,0,targetSum);
    }
};