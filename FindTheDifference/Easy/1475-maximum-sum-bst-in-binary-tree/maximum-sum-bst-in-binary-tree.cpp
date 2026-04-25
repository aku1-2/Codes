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
/*class Solution {
    int ans=0;
public:
   bool isvalidbst(TreeNode* root, long min_val, long max_val){
    if(!root) return true;
     if(min_val>=root->val || max_val<=root->val) return false;
     return isvalidbst(root->left, min_val,root->val)
            && isvalidbst(root->right, root->val,max_val);
   }

   int sumbst(TreeNode* root){
    if(!root) return 0;
    return root->val+ sumbst(root->left) + sumbst(root->right);
   }

   void dfs(TreeNode* root){
    if(!root) return;
    if(isvalidbst(root, LONG_MIN, LONG_MAX)){
        ans= max(ans, sumbst(root));
    }
    dfs(root->left);
    dfs(root->right);

   }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};*/

/*class Solution {
    int ans = 0;
public:
    
    array<int,4> dfs(TreeNode* root) {
        if (!root) return {1, 0, INT_MAX, INT_MIN};

        auto [l_bst, l_sum, l_min, l_max] = dfs(root->left);
        auto [r_bst, r_sum, r_min, r_max] = dfs(root->right);

        if (l_bst && r_bst && l_max < root->val && root->val < r_min) {
            int sum = l_sum + r_sum + root->val;
            ans = max(ans, sum);
            return {1, sum, min(l_min, root->val), max(r_max, root->val)};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};*/

class NodeValue{
public:
    int minNode, maxNode, maxSum;

    NodeValue(int minNode,int maxNode,int maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};
class Solution {
private:
    int ans = 0;

    NodeValue helper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // check BST condition
        if (left.maxNode < root->val && root->val < right.minNode) {
            int sum = left.maxSum + right.maxSum + root->val;
            
            ans = max(ans, sum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                sum
            );
        }

        // not a BST
        return NodeValue(INT_MIN, INT_MAX, 0);
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};