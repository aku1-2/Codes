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
    bool isEvenOddTree(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
       int level=0;
       while(!q.empty()){
        int size= q.size();
        vector<int> array;
        for(int i=0;i<size;i++){
               auto x= q.front();
               q.pop();
               array.push_back(x->val);
               if(x->left) q.push(x->left);
               if(x->right) q.push(x->right);
           }
           if(level%2==0){
            for(int i=0;i<array.size();i++){
               if(array[i]%2==0) return false;
               if(i<array.size()-1 && array[i]>=array[i+1]) return false;
            }
           }
           else{
            for(int i=0;i<array.size();i++){
                if(array[i]%2!=0) return false;
                if(i<array.size()-1 && array[i]<=array[i+1]) return false;
              }
           }
           level++;
       }
       return true;
    }
};