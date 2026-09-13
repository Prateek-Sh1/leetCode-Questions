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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool preN=false;
        while(q.size()>0){
            TreeNode* p=q.front();
            q.pop();
            if(p==NULL){
                preN=true;
                continue;
            }
            if(preN==true)return false;
            if(p->left!=NULL) q.push(p->left);
            else q.push(NULL);

            if(p->right!=NULL) q.push(p->right);
            else q.push(NULL);
        }
        return true;
    }
};