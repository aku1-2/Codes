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
    int i=0;
public:
    TreeNode* BuildTree(vector<int>& preorder,int bound){
        if(i==preorder.size() || preorder[i]>bound)
        return nullptr;
        TreeNode* node= new TreeNode(preorder[i++]);
        node->left= BuildTree(preorder, node->val );
        node->right= BuildTree(preorder, bound );
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return BuildTree(preorder,INT_MAX);
    }
};