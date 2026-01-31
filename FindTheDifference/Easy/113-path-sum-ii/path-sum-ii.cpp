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
vector<vector<int>> ans;
void dfs(TreeNode* root, int targetSum, vector<int>& singlepath){
    if(root==nullptr) return;
    singlepath.push_back(root->val);
    if(root->left==nullptr && root->right ==nullptr && targetSum == root->val)
        ans.push_back(singlepath);
    else{
        dfs(root->left ,targetSum-root->val , singlepath);
        dfs(root->right ,targetSum-root->val , singlepath);
 
    }
    singlepath.pop_back();
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> singlepath;
        dfs(root,targetSum,singlepath);
         return ans;
        }
    
};