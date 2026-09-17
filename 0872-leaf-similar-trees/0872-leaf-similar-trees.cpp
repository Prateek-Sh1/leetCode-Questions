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
    bool t=true;
    vector<int>temp;
    void helper1(TreeNode* root1){
        if(root1==NULL)return ;
        if(root1->left==NULL && root1->right==NULL){
            temp.push_back(root1->val);
            return;
        }
        helper1(root1->left);
        helper1(root1->right);
    }
    int i=0;
    void helper(TreeNode* root2){
        if(root2==NULL) return;
        if(root2->left==NULL && root2->right==NULL){
            if(i<temp.size() && root2->val!=temp[i]){
                t=false;
            }
            i++;
            return;
        }
        helper(root2->left);
        helper(root2->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper1(root1);
        helper(root2);
        return t && i==temp.size();
    }
};