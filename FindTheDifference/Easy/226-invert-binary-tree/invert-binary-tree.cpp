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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==nullptr){
            return nullptr;
        }
       /* TreeNode* root1 = new TreeNode(root->val);
        root1->left = invertTree(root->right);
        root1->right = invertTree(root->left);

        return root1;*/
        //Swapping technique
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;

    }
};