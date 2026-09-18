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
    // opt1->means niche hi answer mil gya
    // opt2->means left ya right se koi acha mil gya with rooot
    // opt3->means left ya right dono ache nhi hai sirf root achha hai
    int mx=INT_MIN;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int l=helper(root->left);
        int r=helper(root->right);

        int opt1=l+r+root->val;
        int opt2=max(l,r)+root->val;
        int opt3=root->val;
        mx=max({mx,opt1,opt2,opt3});
        return max(opt2,opt3);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return mx;
    }
};