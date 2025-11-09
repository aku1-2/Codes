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
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        inorder(root, maxsum);
        return maxsum;

    }
    int inorder(TreeNode* root,int& maxsum){
        if(root==nullptr){
            return 0;
        }
        int leftsum=max(0,inorder(root->left,maxsum));
        int rightsum=max(0,inorder(root->right,maxsum));

        int currentsum= root->val+ leftsum+ rightsum;
        maxsum=max(currentsum,maxsum);

        return root->val + max(leftsum, rightsum); 

    }
};