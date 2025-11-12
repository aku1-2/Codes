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
pair<bool, int> isBalancedfast(TreeNode* root){
    if(root==nullptr){
        pair<bool, int> p= make_pair(true,0);
        return p;
    }
    pair<int ,int> left=isBalancedfast(root->left);
    pair<int ,int> right=isBalancedfast(root->right);
    bool diff= abs(left.second-right.second) <=1;
    int leftans=left.first;
    int rightans =right.first;
    pair<bool,int> ans;
    ans.second=  max(left.second,right.second)+1;
    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{ 
    ans.first=false;
    }
    return ans;

}
    bool isBalanced(TreeNode* root) {
        return isBalancedfast(root).first;
    }
};