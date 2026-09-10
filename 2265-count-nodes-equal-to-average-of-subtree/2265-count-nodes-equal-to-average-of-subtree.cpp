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
    vector<int> sumN(TreeNode* root){
        if(root==NULL)return {0,0};
        vector<int> ls=sumN(root->left);
        vector<int> rs=sumN(root->right);
        return {ls[0]+rs[0]+root->val,ls[1]+rs[1]+1};
    }

    int ans=0;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        vector<int>p=sumN(root);
        if((p[0]/p[1])==root->val){
            ans++;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);

        return ans;
    }
};