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
    long long mod = 1e9+7;
    long long mx=0;
    long long dfs(TreeNode* root,long long totl){
        if(root==NULL) return 0;
        int lft=dfs(root->left,totl);
        int rgt=dfs(root->right,totl);
        long long sum=root->val+lft+rgt;
        long long rem=totl-sum;
        mx=max(mx,sum*rem);
        return sum;
    }
    long long dfsSum(TreeNode* root){
        if(root==NULL) return 0;
        long long l=dfsSum(root->left);
        long long r=dfsSum(root->right);
        return l+r+root->val;
    }
    int maxProduct(TreeNode* root) {
        long long tts=dfsSum(root);
        dfs(root,tts);

        return mx%mod;
    }
};