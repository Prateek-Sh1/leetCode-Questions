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
    TreeNode * res=NULL;
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL) return;
        if(target==original){
            res=cloned;
            return;
        };
        helper(original->left,cloned->left,target);
        helper(original->right,cloned->right,target);

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        helper(original,cloned,target);
        return res;
    }
};