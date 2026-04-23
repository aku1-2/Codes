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
    void inOrder(TreeNode* root , vector<int>& result){
        if(root==nullptr) return;
        inOrder(root->left,result);
        result.push_back(root->val);
        inOrder(root->right,result);
        }

    bool findTarget(TreeNode* root, int k) {
        vector<int> result;
        int ans;
        inOrder(root, result);
        int i = 0, j = result.size() - 1;

    while(i < j){
        int sum = result[i] + result[j];
        if(sum == k) return true;
        else if(sum < k) i++;
        else j--;
    }

        return false;
    }
};