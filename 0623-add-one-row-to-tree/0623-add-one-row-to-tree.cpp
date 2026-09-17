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
    void helper(TreeNode* root,int idx, int tgt, int& val){
        if(idx==tgt){
            if(root!=NULL){
                TreeNode* val1=new TreeNode(val);
                TreeNode* val2=new TreeNode(val);
                val1->left=root->left;
                val2->right=root->right;
                root->left=val1;
                root->right=val2;
                return ;
            }
        }
        if(root->left!=NULL) helper(root->left,idx+1,tgt,val);
        if(root->right!=NULL) helper(root->right,idx+1,tgt,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* val1=new TreeNode(val);
            val1->left=root;
            val1->right=NULL;
            return val1;
        }
        helper(root,1,depth-1,val);
        return root;
    }
};