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
    int mx=0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        if(root->left!=NULL && root->right!=NULL && root->left->val==root->val && root->right->val==root->val){
            mx=max(mx,l+r+2);
            return max(l,r)+1;
        }
        else if(root->left!=NULL && root->left->val==root->val){
            mx=max(mx,l+1);
            return l+1;
        }
        else if(root->right!=NULL && root->right->val==root->val){
            mx=max(mx,r+1);
            return r+1;
        }
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return mx;
    }
};