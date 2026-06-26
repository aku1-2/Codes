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
   unordered_map<int,int> m;
   int index=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        return Helper(preorder, 0, inorder.size()-1);
    }

    TreeNode* Helper(vector<int>& preorder, int left, int right){
         if(left>right){
            return nullptr;
         }
         int mid = m[preorder[index]];
         TreeNode* ans= new TreeNode(preorder[index++]);
         

         ans->left= Helper(preorder, left, mid-1);
         ans->right= Helper(preorder, mid+1, right);
         return ans;
    }
};